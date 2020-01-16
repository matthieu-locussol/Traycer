#include <Core/Renderer.hpp>

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>

#include <Core/Constants.hpp>
#include <Core/Vector.hpp>
#include <Shapes/BaseShape.hpp>
#include <Utils/IO.hpp>
#include <Utils/Lighting.hpp>

Renderer::Renderer(float width, float height, Scene scene, Camera camera) :
    m_width(width),
    m_height(height),
    m_scene(scene),
    m_camera(camera)
{

}

Color Renderer::trace(const Ray& ray, const int& depth) {
    float tNear = INFINITY;
    BaseShape * hit = nullptr;

    for (int i = 0; i < m_scene.getObjects().size(); ++i) {
        float t0 = INFINITY;
        float t1 = INFINITY;

        if (m_scene.getObjects()[i]->intersect(ray, t0, t1)) {
            if (t0 < 0) {
                t0 = t1;
            }

            if (t0 < tNear) {
                tNear = t0;
                hit = m_scene.getObjects()[i];
            }
        }
    }

    if (!hit) {
        if(depth < 1) {
            return m_scene.getBackgroundColor();
        } else {
            return Color();
        }
    }

    Vector3 hitPoint = ray.getOrigin() + ray.getDirection() * tNear;

    Vector3 N = hit->getNormal(hitPoint);
    N.normalize();

    Vector3 V = m_camera.getPosition() - hitPoint;
    V.normalize();

    Color rayColor = Lighting::getLighting(*hit, hitPoint, N, V, m_scene.getLights(), m_scene.getObjects());

    float bias = 1e-4;
    bool inside = false;

    if (ray.getDirection().dot(N) > 0) {
        N = -N;
        inside = true;
    }

    if( (hit->getTransparency() > 0 || hit->getReflectivity() > 0) && depth < MAX_RAY_DEPTH) {
        Vector3 R = ray.getDirection() - N * 2 * ray.getDirection().dot(N);

        R = R + Vector3::random() * hit->getGlossiness();
        R.normalize();

        Ray rRay(hitPoint + N * bias, R);
        Color reflectionColor = trace(rRay, depth + 1);
        Color refractionColor = Color();

        if (hit->getTransparency() > 0) {
            float ni = 1.0;
            float nt = 1.1;
            float nit = ni / nt;

            if(inside) {
                nit = 1 / nit;
            }

            float cosTheta = - N.dot(ray.getDirection());
            float k = 1 - nit * nit * (1 - cosTheta * cosTheta);

            Vector3 T = ray.getDirection() * nit + N * (nit * cosTheta - sqrt(k));
            T = T + Vector3::random() * hit->getGlossyTransparency();
            T.normalize();

            Ray refractionRay(hitPoint - N * bias, T);
            refractionColor = trace(refractionRay, depth + 1);
            rayColor = (reflectionColor * hit->getReflectivity()) + (refractionColor * hit->getTransparency());
        }
        else {
            rayColor = rayColor + (reflectionColor * hit->getReflectivity());
        }
    }

    return rayColor;
}

void Renderer::render(int samples, std::function<void (float)> updateProgress) {
    float inv_samples = 1 / (float) samples;

    Color * image = new Color[m_width * m_height];
    Color * pixel = image;

    for (int y = 0; y < m_height; ++y) {
        updateProgress((float) y / (float) m_height);

        for (int x = 0; x < m_width; ++x, ++pixel) {
            for (int s = 0; s < samples; ++s) {
                Vector3 r = Vector3::random();
                Vector3 p = Vector3(x + r.x, y + r.y, 1);
                Vector3 rayDirection = m_camera.pixelToViewport(p);

                Ray ray(m_camera.getPosition(), rayDirection);

                *pixel += trace(ray, 0) * inv_samples;
            }
        }
    }

    updateProgress(1.0f);

    IO::ImageToPPMFile(image, m_width, m_height);
}