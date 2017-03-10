#ifndef BALL_H
#define BALL_H
#include "vec3.h"
#include <QImage>
#include <QRgb>
#include "intersection.h"
using namespace std;

class ball
{
public:
    ball();
    ~ball();
    void reset(vec3 c,double r,colour bc,double kd,double ks,double ka,double kt,double e,bool hasbmp,string picname);
    intersection FindPoi(vec3 start,vec3 dir);//重要，dir为单位向量，需要给vec3类增加模化为1的函数
    vec3 center;
    double radius;
    colour _colour;//除以255即为漫反射系数Kd的分量
    double Ks;
    double Ka;
    double Kd;
    double Kt;
    double eta;
    bool tietu;
    string pic;
    QImage* img;
};

#endif // BALL_H
