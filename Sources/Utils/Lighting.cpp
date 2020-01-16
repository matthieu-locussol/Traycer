#include <Utils/Lighting.hpp>

namespace Lighting {
    Color getLighting(const BaseShape& object, const Vector3& point, const Vector3& normal, const Vector3& view, const BaseLight * light) {
        Color rayColor;

        Vector3 N = normal;
        Vector3 L = light->getPosition() - point;
        float distance = L.length();
        L.normalize();

        float attenuate = light->attenuate(distance);
        float NdotL = N.dot(L);
        float intensity = max(0.0f, NdotL);

        Color diffuse = object.getColor() * light->getIntensity() * intensity * attenuate;

        Vector3 V = view;
        Vector3 H = L + V;
        H.normalize();

        float shinniness = object.getShininess();
        float NdotH = N.dot(H);
        float specularIntensity = pow(max(0.0f, NdotH), shinniness);
        Color specular = object.getColorSpecular() * light->getIntensity() * specularIntensity * attenuate;

        rayColor = diffuse * object.getKd() + specular * object.getKs();

        return rayColor;
    }

    Color getLighting(const BaseShape& object, const Vector3& point, const Vector3& normal, const Vector3& view, const vector<BaseLight*>& lights, const vector<BaseShape*>& objects) {
        Color ambient = object.getColor();
        Color rayColor = ambient * object.getKa();

        for(int i = 0; i < lights.size(); ++i) {
            float shadowFactor = getShadowFactor(point, *lights[i], objects);
            rayColor += getLighting(object, point, normal, view, lights[i]) * (1.0 - shadowFactor);
        }

        return rayColor;
    }

    Color getLightingSimple(const BaseShape& object, const Vector3& point, const Vector3& normal, const Vector3& view, const vector<BaseLight*>& lights, const vector<BaseShape*>& objects) {
        Color ambient = object.getColor();
        Color rayColor = ambient * object.getKa();

        for(int i = 0; i < lights.size(); ++i) {
            bool isInShadow = getShadow(point, *lights[i], objects);

            if (!isInShadow) {
                rayColor +=  getLighting(object, point, normal, view, lights[i]);
            }
        }

        return rayColor;
    }

    bool getShadow(const Vector3& point, const BaseLight& light, const vector<BaseShape*>& objects) {
        Vector3 shadowRayDirection = light.getPosition() - point;
        shadowRayDirection.normalize();

        Ray shadowRay(point, shadowRayDirection);

        bool isInShadow = false;

        for(int j = 0; j < objects.size(); ++j) {
            float t0 = INFINITY;
            float t1 = INFINITY;

            if(objects[j]->intersect(shadowRay, t0, t1)) {
                isInShadow = true;
                break;
            }
        }

        return isInShadow;
    }

    float getShadowFactor(const Vector3& point, const BaseLight& light, const vector<BaseShape*>& objects) {
        if(light.getType() == 0x20) {
            int shadowCount = 0;

            Vector3 start(light.getPosition().x - (light.getWidth() / 2), light.getPosition().y - (light.getHeight() / 2), light.getPosition().z);
            Vector3 step(light.getWidth() / light.getSamples(), light.getHeight() / light.getSamples(), 0);
            Vector3 lightSample;
            Vector3 jitter;

            for(int i = 0; i < light.getSamples(); ++i) {
                for(int j = 0; j < light.getSamples(); ++j) {
                    jitter = Vector3::random() * step - (step / 2.0);
                    lightSample = Vector3(start.x + (step.x * i) + jitter.x, start.y + (step.y * j) + jitter.y, start.z);

                    Vector3 shadowRayDirection = lightSample - point;
                    shadowRayDirection.normalize();
                    Ray shadowRay(point, shadowRayDirection);

                    bool isInShadow = false;

                    for(int j = 0; j < objects.size(); ++j) {
                        float t0 = INFINITY;
                        float t1 = INFINITY;

                        if(objects[j]->intersect(shadowRay, t0, t1)) {
                            isInShadow = true;
                            break;
                        }
                    }

                    if(isInShadow) {
                        shadowCount++;
                    }
                }
            }

            return shadowCount / (float)(light.getSamples());
        }
        else {
            bool isInShadow = getShadow(point, light, objects);

            if(isInShadow) {
                return 1.0;
            } else {
                return 0.0;
            }
        }

    }
}