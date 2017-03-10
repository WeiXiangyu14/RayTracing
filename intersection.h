#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "vec3.h"
#include "colour.h"

class intersection
{
public:
    intersection(vec3 l,vec3 nv,double d2s);
    ~intersection();
    vec3 pos;//交点位置
    vec3 normalVec;//法向量
    double dis2start;//距起点距离的平方，仅用于比较大小
    colour icolour;//除以255即Kd的分量
    double Ks;
    double Ka;
    double Kd;
    double Kt;
    double eta;
};

#endif // INTERSECTION_H
