#ifndef HEADER_RENDERER_HPP
#define HEADER_RENDERER_HPP

#include <functional>

#include <Core/Camera.hpp>
#include <Core/Color.hpp>
#include <Core/Ray.hpp>
#include <Core/Scene.hpp>

class Renderer {
    public:
        Renderer(float width, float height, Scene scene, Camera camera);

        Color trace(const Ray& ray, const int& depth);
        void render(int samples, std::function<void (float)> updateProgress);

    private:
        int m_width;
        int m_height;

        Scene m_scene;

        Camera m_camera;
};

#endif // HEADER_RENDERER_HPP