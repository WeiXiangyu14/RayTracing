#ifndef SCREEN_H
#define SCREEN_H
#include <cstring>
#include "colour.h"
#include "pixel.h"
#include "vec3.h"
//#define HEIGHT 600;
//#define WIGTH 800;



class screen//与xOz平面平行
{
public:
    screen();
    ~screen();
    void reset(vec3 lu,double w,double h,vec3 cam);
    void OutputBmp();//参数：左上角位置，宽，高，相机位置
    vec3 leftup;
    double width;
    double height;
    pixel _pixel[W_NUM][H_NUM];
    vec3 camera;
    std::string outfile;
};

#endif // SCREEN_H
