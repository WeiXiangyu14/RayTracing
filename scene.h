#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include "vec3.h"
#include "intersection.h"
#include "screen.h"
#include "ball.h"
#include "lightsource.h"
#include "colour.h"
#include "flat.h"

using namespace std;

class scene
{
public:
    scene();
    ~scene();

    std::vector<ball> _ball;
    std::vector<flat> _flat;

    void AddStuff(vec3 c,double r,colour cl,double kd,double ks,double ka,double kt,double e,bool hasbmp,string picname);//先只写加球
    void AddFlat(vec3 nn, double DD, colour bc,double kd, double ks, double ka,double kt,double e,bool hasbmp,string picname);
    intersection findIntersection(vec3 start,vec3 dir);

};

#endif // SCENE_H
