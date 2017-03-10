#include "ball.h"

ball::ball()
{

}

ball::~ball()
{

}

void ball::reset(vec3 c, double r, colour bc, double kd, double ks, double ka, double kt, double e,bool hasbmp,string picname)
{
    img = new QImage;
    center=c;
    radius=r;
    _colour = bc;
    Ks = ks;
    Ka = ka;
    Kd = kd;
    Kt = kt;
    eta = e;
    tietu = hasbmp;
    pic = picname;

    if(tietu)
    {
        img->load(pic.c_str());
    }
}

intersection ball::FindPoi(vec3 start, vec3 dir)//重要：没考虑光线在球内
{//dir为方向向量,模为1
    intersection noPoint(center,center,-1);//-1表示无交点 
    vec3 _start = start;



    vec3 stoc = center - _start;//先做判断：如果起点在球面上，且光线方向与起点到球心的向量乘积小于0，必无交点
    double per =(stoc.Dis2zero() - radius)/radius;
    if( per>-0.001 && per<0.001)
    {
        double test = stoc.x*dir.x + stoc.y*dir.y + stoc.z*dir.z;
        if(test < 0)
        {
            vec3 les =  stoc * 0.01;
            _start -= les;
        //    return noPoint;
        }
        else//球面附近，朝向球心的光线全部设为从球面内部发出
        {
//            intersection yesPoint(center,center,1);
//            return yesPoint;
//            qDebug()<<"center:"<<center.x<<" "<<center.y<<" "<<center.z<<endl;
//            qDebug()<<"o:";
//            _start.showinfo();
//            qDebug()<<"stoc:";
//            stoc.showinfo();
            vec3 les = stoc * 0.01;
//            qDebug()<<"les:"<<les.x<<" "<<les.y<<" "<<les.z<<endl;
            _start += les;
        }
    }



    bool inBall = true;
    double Loc2 = center.Dis22(_start);
    if(Loc2 > radius*radius)
        inBall=false;

    double tca = (center.x-_start.x)*dir.x + (center.y-_start.y)*dir.y + (center.z-_start.z)*dir.z;

    if(!inBall)
    {
        if(tca < 0) //无交点
        {
            return noPoint;
        }

        double thc2 = radius*radius - Loc2 + tca*tca ;

        if(thc2 < 0)
            return noPoint;

        double t = tca - sqrt(thc2);

        vec3 cp;//交点位置
        cp = _start + (dir*t);

        vec3 nv;//法向量
        nv = cp - center;
        nv.setModule1();

        double d2s2=cp.Dis22(_start);//距光线发出点距离的平方

        intersection itst(cp,nv,d2s2);
        if(tietu)
        {

            double bx = nv.x;
            double by = nv.z;
            int px = (double(1+bx)/2)*img->width();
            int py = (double(1-by)/2)*img->height();
            if(py >= img->height())
                py = img->height() - 1;
            if(px >= img->width())
                py = img->width() - 1;
            if(py < 0)
                py = 0;
            if(px < 0)
                px = 0;
            QRgb t = img->pixel(px,py);
            colour tcolour(qRed(t),qGreen(t),qBlue(t));
            itst.icolour = tcolour;
        }
        else
            itst.icolour = _colour;
        itst.Ka = Ka;
        itst.Ks = Ks;
        itst.Kd = Kd;
        itst.Kt = Kt;
        itst.eta = 1/eta;

        return itst;
    }
    else //起点在球内
    {
        double thc2 = radius*radius - Loc2 + tca*tca ;

        double t = tca + sqrt(thc2);

        vec3 cp;//交点位置
        cp = _start + (dir*t);

        vec3 nv;//法向量
        nv = center - cp;
        nv.setModule1();

        double d2s2=cp.Dis22(_start);//距光线发出点距离的平方

        intersection itst(cp,nv,d2s2);
        itst.icolour = _colour;
        itst.Ka = Ka;
        itst.Ks = Ks;
        itst.Kd = Kd;
        itst.Kt = Kt;
        itst.eta = eta;
        return itst;
    }

}
