#include <ctime>
#include <iostream>
#include <fstream>

#include <Core/Camera.hpp>
#include <Core/Constants.hpp>
#include <Core/Parser.hpp>
#include <Core/Renderer.hpp>
#include <Core/Scene.hpp>
#include <Lights/AmbientLight.hpp>
#include <Lights/AreaLight.hpp>
#include <Shapes/Sphere.hpp>

void Scene1(int width, int height, float fov, int samples);

int main(int argc, char * argv[]) {
    if(Parser::hasOption(argv, argv + argc, "--help")) {
        std::cout << "Usage: " << argv[0];
        std::cout << " [-s samples=" << DEFAULT_SAMPLES << "]";
        std::cout << " [-w width=" << DEFAULT_WIDTH << "]";
        std::cout << " [-h height=" << DEFAULT_HEIGHT << "]";
        std::cout << " [-f fov=" << DEFAULT_FOV << "]";
        std::cout << " [--help]" << std::endl;

        return EXIT_SUCCESS;
    }

    char * s = Parser::getOption(argv, argv + argc, "-s");
    char * w = Parser::getOption(argv, argv + argc, "-w");
    char * h = Parser::getOption(argv, argv + argc, "-h");
    char * f = Parser::getOption(argv, argv + argc, "-f");

    int samples = (s) ? std::atoi(s) : DEFAULT_SAMPLES;
    int width = (w) ? std::atoi(w) : DEFAULT_WIDTH;
    int height = (h) ? std::atoi(h) : DEFAULT_HEIGHT;
    float fov = (f) ? (float)(std::atoi(f)) : DEFAULT_FOV;

    Scene1(width, height, fov, samples);

    return EXIT_SUCCESS;
}

auto updateProgress = [](float progress) {
    int progressValue = (int)(progress * 100);

    std::cout << " |";
    for(int i = 0 ; i < 100 ; i += 2) {
        std::cout << (i < progressValue ? "=" : "-");
    }
    std::cout << "| " << progressValue << " %\r";

    std::cout.flush();
};

void Scene1(int width, int height, float fov, int samples) {
    std::cout << "Generating scene..." << std::endl;
    std::clock_t t = std::clock();

    Scene scene = Scene();

    Sphere s0 = Sphere( Vector3(0, -10008, 20), 10000, Color(0x00, 0x6A, 0x80), 0.2, 0.5, 0.0, 128.0, 0.0);
    Sphere s1 = Sphere( Vector3(0, 0, 20), 4, Color(0x1E, 0x88, 0xE5), 0.3, 0.8, 0.5, 128.0, 0.2, 0.45);
    s1.setGlossiness(0.05);
    s1.setGlossyTransparency(0.02);
    Sphere s2 = Sphere( Vector3(5, -1, 15), 2, Color(0xFD, 0xD8, 0x35), 0.4, 0.6, 0.4, 128.0, 0.4);
    s2.setGlossiness(0.2);
    Sphere s3 = Sphere( Vector3(5, 0, 25), 3, Color(0x5D, 0x40, 0x37), 0.3, 0.8, 0.1, 128.0, 0.4);
    s3.setGlossiness(0.1);
    Sphere s4 = Sphere( Vector3(-3.5, -1, 10), 2, Color(0xFF, 0xAB, 0x91), 0.4, 0.6, 0.5, 64.0, 0.4);
    s4.setGlossiness(0.4);
    Sphere s5 = Sphere( Vector3(-5.5, 0, 15), 3, Color(0x30, 0x30, 0x30), 0.3, 0.8, 0.25, 32.0, 0.0);

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
    Camera camera = Camera( Vector3(0, 20, -20), width, height, fov);
    camera.setAngleX(30 * M_PI / 180.0);

    // Create Renderer
    Renderer r = Renderer(width, height, scene, camera);
    r.render(samples, updateProgress);

    t = std::clock() - t;
    std::cout << std::endl << "Scene complete." << std::endl << std::endl;
    std::cout << "Time ellpased: " << ((float)t) / CLOCKS_PER_SEC << " seconds." << std::endl;
}