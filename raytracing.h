#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "scene.h"

class RayTracing
{
public:
    RayTracing();
    ~RayTracing();
    scene _scene();
    vec3 _camera;
    screen _screen;
    void run();
    colour Tracing(vec3 start,vec3 dir,double weight);
};

#endif // RAYTRACING_H
