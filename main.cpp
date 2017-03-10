#include <QApplication>
#include <QDebug>
#include <QImage>
#include <QRgb>
#include "raytracer.h"

using namespace std;

int main(int argc, char *argv[])
{
    qDebug()<<"begin"<<endl;
    RayTracer* rayTracer = new RayTracer;
    rayTracer -> SetInfo();
    //背景颜色，环境光，光源均在RayTracer的构造函数中设定
//    vec3 b1c(6000,5000,4000);
//    colour b1colour(0,255,0);

//    rayTracer->_scene.AddStuff(b1c , 1400 , b1colour ,0.1 ,0.1);

//    vec3 camera(5000,-5000,5000);
//    rayTracer->_camera = camera;

//    qDebug()<<"camera over"<<endl;

//    vec3 screen_lu(2000,0,8000);
//    rayTracer->_screen.reset(screen_lu,6000,6000,camera);

//    qDebug()<<"300,300"<<rayTracer->_screen._pixel[31][29].pos.x<<" "<<rayTracer->_screen._pixel[31][29].pos.y<<" "<<rayTracer->_screen._pixel[31][29].pos.z<<endl;

    rayTracer->run();

//    QImage* img = new QImage;
//    if(img->load("stone.jpg"))
//        qDebug()<<"load over"<<endl;
//    QRgb t = img->pixel(1200,100);
//    qDebug()<<qRed(t)<<" "<<qGreen(t)<<" "<<qBlue(t)<<endl;
//    qDebug()<<img->width()<<" "<<img->height()<<" "<<endl;
//    img->save("ss.jpg");

    return 0;
}
