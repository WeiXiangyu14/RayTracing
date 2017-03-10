#include "scene.h"

scene::scene()
{

}

scene::~scene()
{

}

intersection scene::findIntersection(vec3 start, vec3 dir)
{
    intersection noPoint(start,start,-1);
    int s = _ball.size();
    int f = _flat.size();
    if(s == 0 && f == 0)
        return noPoint;
    std::vector<intersection> tmpIts;

//    qDebug()<<"_ball.size()="<<s<<endl;

    for(int i=0;i<s;i++)
    {
        tmpIts.push_back(_ball[i].FindPoi(start,dir));
    }

    for(int i=0;i<f;i++)
    {
        tmpIts.push_back(_flat[i].FindPoi(start,dir));
    }

    int it=tmpIts.size();
    double mindis = 100000000;
    int res = -1;

//    qDebug()<<""<<tmpIts[0].dis2start<<endl;

    for(int i=0;i<it;i++)//找所有交点中最近的
    {
        if(tmpIts[i].dis2start < mindis && tmpIts[i].dis2start > 0)
        {
            mindis = tmpIts[i].dis2start;
            res = i;
        }
    }

    if(res<0)
        return noPoint;
    else
        return tmpIts[res];
}

void scene::AddStuff(vec3 c, double r, colour cl, double kd, double ks, double ka, double kt, double e, bool hasbmp, string picname)
{
    ball newball;
    newball.reset(c,r,cl,kd,ks,ka,kt,e,hasbmp,picname);
    _ball.push_back(newball);
}

void scene::AddFlat(vec3 nn, double DD, colour bc, double kd, double ks, double ka, double kt, double e, bool hasbmp, string picname)
{
    flat newflat;
    newflat.reset(nn,DD,bc,kd,ks,ka,kt,e,hasbmp,picname);

    _flat.push_back(newflat);
}
