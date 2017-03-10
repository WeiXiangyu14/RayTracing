#include "flat.h"

flat::flat()
{
    minx = 685;
    maxx = 2000;
    minz = 645;
    maxz = 1850;
}

flat::~flat()
{

}

void flat::reset(vec3 nn, double DD, colour bc, double kd, double ks, double ka, double kt, double e, bool hasbmp, string picname)
{
    img = new QImage;
    n = nn;
//    P = PP;
    D = DD;
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
        qDebug()<<pic.c_str()<<endl;
        img->load(pic.c_str());
//        qDebug()<<"pic.c_str()"<<endl;
    }
}

intersection flat::FindPoi(vec3 start, vec3 dir)
{
    vec3 _start = start;
    intersection noPoint(n,n,-1);//-1表示无交点
    double nRo = n.x * _start.x + n.y * _start.y + n.z * _start.z;
    double nRd = n.x*dir.x + n.y*dir.y + n.z*dir.z;
    if( nRd == 0)
        return noPoint;



    double t = -(D + nRo)/(nRd);

    if(t<0)
        return noPoint;



    vec3 nv;//法向量
    if(nRd < 0)
        nv = n;
    else
        nv = -n;
    nv.setModule1();

//    if( (nRo + D) < 0.2 && (nRo + D) > -0.2)
//        _start += (nv*0.4);

    vec3 cp;//交点位置
    cp = _start + (dir*t);
    cp += (nv*0.1);

    double d2s2=cp.Dis22(_start);
    intersection itst(cp,nv,d2s2);
//    if(tietu && cp.x>minx && cp.x<maxx && cp.z>minz && cp.z<maxz)
//    {
// //       qDebug()<<"here"<<endl;
//        double bx = cp.x;
//        double bz = cp.z;
//        int px = (double(bx-minx)/(maxx-minx))*img->width();
//        int py = (double(maxz-bz)/(maxz-minz))*img->height();
//        if(py >= img->height())
//            py = img->height() - 1;
//        if(px >= img->width())
//            py = img->width() - 1;
//        if(py < 0)
//            py = 0;
//        if(px < 0)
//            px = 0;
//        QRgb t = img->pixel(px,py);
//        colour tcolour(qRed(t),qGreen(t),qBlue(t));
//        itst.icolour = tcolour;
//    }
    if(tietu)
    {
        int bx = cp.x;
        int by = cp.y;
        bx %= 1200;
        by %= 1200;
        if(bx<0)
            bx += 1200;
        if(by<0)
            by += 1200;
        int px = (double(bx)/1200)*img->width();
        int py = (double(by)/1200)*img->height();
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
    itst.eta = eta;

    return itst;

}
