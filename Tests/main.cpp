#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

#include <Core/Camera.hpp>
#include <Core/Constants.hpp>
#include <Core/Parser.hpp>
#include <Core/Renderer.hpp>
#include <Core/Scene.hpp>
#include <Lights/AmbientLight.hpp>
#include <Lights/AreaLight.hpp>
#include <Shapes/Sphere.hpp>

void Scene1(int width, int height, float fov, int samples) {
    Scene scene = Scene();

    Sphere s0 = Sphere( Vector3(0, -10008, 20), 10000, Color(20, 120, 100), 0.2, 0.5, 0.0, 128.0, 0.0);
    Sphere s1 = Sphere( Vector3(0, 0, 20), 4, Color(165, 10, 14), 0.3, 0.8, 0.5, 128.0, 0.4);
    Sphere s2 = Sphere( Vector3(5, -1, 15), 2, Color(235, 179, 41), 0.4, 0.6, 0.4, 128.0, 0.4);
    Sphere s3 = Sphere( Vector3(5, 0, 25), 3, Color(6, 72, 111), 0.3, 0.8, 0.1, 128.0, 0.4);
    s3.setGlossiness(0.1);
    Sphere s4 = Sphere( Vector3(-3.5, -1, 10), 2, Color(8, 88, 56), 0.4, 0.6, 0.5, 64.0, 0.4);
    Sphere s5 = Sphere( Vector3(-5.5, 0, 15), 3, Color(51, 51, 51), 0.3, 0.8, 0.25, 32.0, 0.0);

    scene.addObject( &s0 );
    scene.addObject( &s1 );
    scene.addObject( &s2 );
    scene.addObject( &s3 );
    scene.addObject( &s4 );
    scene.addObject( &s5 );

    // Add light to scene
    scene.addAmbientLight ( AmbientLight( Vector3(1.0) ) );
    AreaLight l0 = AreaLight( Vector3(0, 20, 35), Vector3(1.4) );
    AreaLight l1 = AreaLight( Vector3(20, 20, 35), Vector3(1.8) );
    scene.addLight( &l0 );
    scene.addLight( &l1 );

    // Add camera
    Camera camera = Camera( Vector3(0,0,-20), width, height, fov);
    camera.setPosition(Vector3(0, 20, -20));
    camera.setAngleX(30 * M_PI / 180.0);

    auto updateProgress = [](float progress){};

    // Create Renderer
    Renderer r = Renderer(width, height, scene, camera);
    r.render(samples, updateProgress);
}

bool compareFiles(const std::string& p1, const std::string& p2) {
    std::ifstream f1(p1, std::ifstream::binary | std::ifstream::ate);
    std::ifstream f2(p2, std::ifstream::binary | std::ifstream::ate);

    if (f1.fail() || f2.fail()) {
        return false;
    }

    if (f1.tellg() != f2.tellg()) {
        return false;
    }

    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);

    return std::equal(
        std::istreambuf_iterator<char>(f1.rdbuf()),
        std::istreambuf_iterator<char>(),
        std::istreambuf_iterator<char>(f2.rdbuf())
    );
}

TEST_CASE( "Generated image matches the reference file", "[Traycer]" ) {
    Scene1(800, 600, 30, 8);

    REQUIRE( compareFiles("scene.ppm", "References/reference.ppm") );
}