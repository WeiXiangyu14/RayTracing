#include "intersection.h"

intersection::intersection(vec3 l, vec3 nv, double d2s)
{
    pos=l;
    normalVec=nv;
    dis2start=d2s;
    Ks = 0;
    Ka = 0;
    Kd = 1;
    Kt = 0;
    eta = 1;
//    icolour = new colour(0,0,0);
}

intersection::~intersection()
{

}
