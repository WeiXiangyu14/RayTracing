#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "scene.h"
#include "lightsource.h"
#include <ctime>
#include <cstdlib>

class RayTracer
{
public:
    RayTracer();
    ~RayTracer();
    scene _scene;
    vec3 _camera;
    screen _screen;
    colour background;
    colour background2;
    colour Ia;//环境光
    lightsource centerlamp;
    lightsource lamp[softShadowNum][softShadowNum];
    void run();
    colour RayTracing(vec3 start,vec3 dir,double weight);
    colour CalcPhong(intersection it, vec3 _start, lightsource lmp);//用Phong模型算局部光照
    vec3 CalcReflect(vec3 lt,vec3 normalv);//计算反射的向量
    vec3 CalcZheshe(vec3 lt,intersection cp);
    double InShadow(intersection it, lightsource lmp);
    void SetInfo();
};

#endif // RAYTRACER_H
