#include "screen.h"
#include <QImage>
#include <QRgb>

screen::screen()
{
    outfile = "0.jpg";
}

screen::~screen()
{

}

void screen::reset(vec3 lu, double w, double h, vec3 cam)
{
    leftup = lu;
    width = w;
    height = h;
    camera = cam;

    double luz=leftup.z;
    double lux=leftup.x;


    for(int i=0;i<W_NUM;i++)
    {
        for(int j=0;j<H_NUM;j++)
        {
            _pixel[i][j].resetcamera(camera);
            double tempx=lux + double(i)*width/double(W_NUM);
            double tempz=luz - double(j)*height/double(H_NUM);
            vec3 tmpvec(tempx,0,tempz);
            _pixel[i][j].resetpos(tmpvec);
        }
    }
//    qDebug()<<"reset screen over"<<endl;
}

void screen::OutputBmp()
{
    QImage* img = new QImage(W_NUM,H_NUM,QImage::Format_RGB888);
    for(int i=0;i<W_NUM;i++)
    {
        for(int j=0;j<H_NUM;j++)
        {
            int r = _pixel[i][j].pcolour.r;
            int g = _pixel[i][j].pcolour.g;
            int b = _pixel[i][j].pcolour.b;
//            for(int k=0;k<AntiAls;k++)
//                for(int l=0;l<AntiAls;l++)
//                {
//                    r += _pixel[i*AntiAls+k][j*AntiAls+l].pcolour.r / double(AntiAls*AntiAls);
//                    g += _pixel[i*AntiAls+k][j*AntiAls+l].pcolour.g / double(AntiAls*AntiAls);
//                    b += _pixel[i*AntiAls+k][j*AntiAls+l].pcolour.b / double(AntiAls*AntiAls);
//                }



            QRgb  q = qRgb(r,g,b);
            img -> setPixel(i,j,q);

        }
    }
    qDebug()<<"set picture over"<<endl;
    img->save(outfile.c_str());
}
