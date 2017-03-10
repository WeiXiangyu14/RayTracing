#ifndef FLAT_H
#define FLAT_H
#include "vec3.h"
#include "intersection.h"
#include <QImage>
#include <QRgb>

using namespace std;

class flat
{
public:
    flat();
    ~flat();
    void reset(vec3 nn,double DD, colour bc, double kd, double ks, double ka,double kt,double e,bool hasbmp,string picname);
    intersection FindPoi(vec3 start,vec3 dir);//重要，dir为单位向量，需要给vec3类增加模化为1的函数
    vec3 n;
    vec3 P;
    double D;
    colour _colour;//除以255即为漫反射系数Kd
    double Ks;
    double Ka;
    double Kd;
    double Kt;
    double eta;
    bool tietu;
    string pic;
    QImage* img;
    double minx,minz,maxx,maxz;
};

#endif // FLAT_H
