#ifndef HEADER_CONSTANTS_HPP
#define HEADER_CONSTANTS_HPP

#if defined __linux__ || defined __APPLE__
#else
#define M_PI 3.141592653589793
#define INFINITY 1e8
#endif

#define MAX_RAY_DEPTH 5

#define K_EPSILON 0.00001

#define DEFAULT_WIDTH 1600
#define DEFAULT_HEIGHT 1200
#define DEFAULT_FOV 30.0
#define DEFAULT_SAMPLES 128

#endif // HEADER_CONSTANTS_HPP