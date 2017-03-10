#include "raytracer.h"
#include <QDebug>

RayTracer::RayTracer()
{
    background.r = 80;
    background.g = 80;
    background.b = 80;

    background2.r = 0;
    background2.g = 0;
    background2.b = 180;

    Ia.r = 50;
    Ia.g = 50;
    Ia.b = 50;//环境光为微弱的蓝光

    centerlamp.pos.x = 1350;//设置光源位置
    centerlamp.pos.y = 1000;
    centerlamp.pos.z = 1830;

    srand(time(0));
    double rdx = 0;
    double rdy = 0;


    for(int i=0;i<softShadowNum;i++)
    {
        for(int j=0;j<softShadowNum;j++)
        {
            rdy = double(rand()%lampDis);
            rdx = double(rand()%lampDis);
//            qDebug()<<rdx<<" "<<rdy<<endl;
            lamp[i][j].pos.x = centerlamp.pos.x + i*lampDis + lampDis/2 - rdx;
            lamp[i][j].pos.y = centerlamp.pos.y + j*lampDis + lampDis/2 - rdy;
            lamp[i][j].pos.z = centerlamp.pos.z;
        }
    }
}

RayTracer::~RayTracer()
{

}

void RayTracer::SetInfo()
{
    vec3 b1center(1550,750,1250);
    colour b1colour(0,140,190);
    _scene.AddStuff(b1center , 220 , b1colour ,0.3 ,0 ,0 ,0.8 ,0.6,false,"");


    vec3 b2center(1200,1760,1250);
    colour b2colour(30,220,20);
    _scene.AddStuff(b2center , 210 , b2colour ,0.2 , 0.7 ,0.1 ,0 ,1,false,"");

//    vec3 b3center(1050,1600,990);
//    colour b3colour(18,200,160);
//    _scene.AddStuff(b3center , 140 , b3colour , 1.1 ,0 ,0.1 ,0 ,1,true,"stone3.jpg");

    vec3 f1n(0,1,0);//正面墙
    double f1D = -3000;
    colour f1colour(220,170,250);
    _scene.AddFlat(f1n,f1D,f1colour,0.5,0,0.1 ,0 ,1,false,"brick.jpg");

    vec3 f2n(-1,0.1,0);//左面墙
    double f2D = 550;
    colour f2colour(220,200,200);
    _scene.AddFlat(f2n,f2D,f2colour,0.3,0.7,0.1 ,0 ,1,false,"");

    vec3 f3n(-1,-0.1,0);//右面墙
    double f3D = 2150;
    colour f3colour(0,190,240);
    _scene.AddFlat(f3n,f3D,f3colour,1.0,0,0.1 ,0 ,1,false,"");

    vec3 f4n(0,-0.05,-1);//天花板
    double f4D = 1900;
    colour f4colour(240,240,240);
    _scene.AddFlat(f4n,f4D,f4colour,1.8,0,0.4 ,0 ,1,false,"");

    vec3 f5n(0,0.05,-1);//地面
    double f5D = 750;
    colour f5colour(220,220,220);
    _scene.AddFlat(f5n,f5D,f5colour,1.2,0,0.2 ,0 ,1,false,"bw.jpg");

//    vec3 b1center(950,760,1210);
//    colour b1colour(180,230,160);
//    _scene.AddStuff(b1center , 170 , b1colour , 1.0 ,0.09 ,0.1 ,0 ,1,true,"stone3.jpg");


//    vec3 b2center(1700,800,1210);//反射
//    colour b2colour(240,100,220);
//    _scene.AddStuff(b2center , 150 , b2colour ,0.1 , 0.7 ,0.1 ,0 ,1,false,"");

//    vec3 b3center(1250,1530,1525);
//    colour b3colour(100,250,150);
//    _scene.AddStuff(b3center , 170 , b3colour ,0.1 ,0.7 ,0.1 ,0 ,0.6,false,"");

    //    vec3 b1center(1150,950,1350);
    //    colour b1colour(0,140,190);
    //    _scene.AddStuff(b1center , 200 , b1colour ,0.3 ,0 ,0 ,0.8 ,0.6,false,"");


    //    vec3 b2center(1600,1360,1300);
    //    colour b2colour(220,220,220);
    //    _scene.AddStuff(b2center , 180 , b2colour ,0.5 , 0.6 ,0.1 ,0 ,1,false,"");

    //    vec3 b3center(1050,1600,990);
    //    colour b3colour(18,200,160);
    //    _scene.AddStuff(b3center , 140 , b3colour , 1.1 ,0 ,0.1 ,0 ,1,true,"stone3.jpg");

    //    vec3 f1n(0,1,0);//正面墙
    //    double f1D = -2000;
    //    colour f1colour(220,220,140);
    //    _scene.AddFlat(f1n,f1D,f1colour,1.2,0,0.1 ,0 ,1,true,"brick.jpg");

    //    vec3 f2n(-1,0.1,0);//左面墙
    //    double f2D = 550;
    //    colour f2colour(140,230,40);
    //    _scene.AddFlat(f2n,f2D,f2colour,1.0,0,0.1 ,0 ,1,false,"");

    //    vec3 f3n(-1,-0.1,0);//右面墙
    //    double f3D = 2150;
    //    colour f3colour(230,100,120);
    //    _scene.AddFlat(f3n,f3D,f3colour,1.0,0,0.1 ,0 ,1,false,"");

    //    vec3 f4n(0,-0.05,-1);//天花板
    //    double f4D = 1900;
    //    colour f4colour(240,240,140);
    //    _scene.AddFlat(f4n,f4D,f4colour,1.8,0,0.4 ,0 ,1,false,"");


    //x 2400 y 15000 z 2700
    vec3 camera(1350,-3000,1350);//相机
    _camera = camera;

    vec3 screen_lu(750,0,1800);//屏幕
    _screen.reset(screen_lu,1200,900,camera);//800,900
    _screen.outfile = "38.jpg";
}

void RayTracer::run()
{
    qDebug()<<"run start"<<endl;
    double ai = 1200/double(W_NUM);
    vec3 dx;
    vec3 dz;
    dx.x = ai;
    dz.z = -ai;
    for(int i=0;i<W_NUM;i++)
    {
        for(int j=0;j<H_NUM;j++)
        {
            for(int k=0;k<AntiAls;k++)
                for(int l=0;l<AntiAls;l++)
                {

                    vec3 tmpdir = (_screen._pixel[i][j].pos + dx*k + dz*l) - _camera;
                    tmpdir.setModule1();
                    _screen._pixel[i][j].pcolour += (RayTracing(_camera,tmpdir,0.7)/double(AntiAls*AntiAls));

                }
        }
        qDebug()<<double(i)/double(W_NUM);
        qDebug()<<endl;
    }
  //  qDebug()<<"run"<<endl;

//    vec3 tmpdir = _screen._pixel[400][300].pos - _camera;
//    tmpdir.setModule1();
//    _screen._pixel[400][300].pcolour = RayTracing(_camera,tmpdir,0.7);




    _screen.OutputBmp();
}

colour RayTracer::RayTracing(vec3 start, vec3 dir, double weight)
{
    if(weight<MinWeight)
        return background2;
    intersection it = _scene.findIntersection(start,dir);
    if(it.dis2start < 0)//没有交点
    {
        return background;
    }
    else//有交点，追踪
    {
        colour Ilocal;
        double s2 = double (softShadowNum*softShadowNum);
        for(int i=0;i<softShadowNum;i++)
            for(int j=0;j<softShadowNum;j++)
               Ilocal += CalcPhong(it,start,lamp[i][j])/s2;

        colour Ir;
        if(it.Ks > eps)
        {

            vec3 Rdir = CalcReflect(-dir,it.normalVec);
            Ir = RayTracing(it.pos ,Rdir ,weight*wr);
            Ir *= it.Ks;

        }

        colour It;
        if(it.Kt > eps)
        {
            vec3 Zdir = CalcZheshe(-dir,it);
            It = RayTracing(it.pos ,Zdir ,weight*wr);
            It *= it.Kt;
        }

        colour ans;
        ans = Ilocal;
        ans += Ir;
        ans += It;
        ans.Confine();
        return ans;

    }
}

colour RayTracer::CalcPhong(intersection it,vec3 _start,lightsource lmp)
{
    colour Ie;
    double Ka = it.Ka;
    Ie = Ia;
    Ie *= Ka;

    double shadowminus = 1;
    shadowminus = InShadow(it,lmp);

    colour I;

    colour Kdrgb = it.icolour / 255;
    double k = it.Kd;
    colour Id;
    Id = Kdrgb * lmp.Ip;
    Id *= k;
    vec3 L = lmp.pos - it.pos;
    L.setModule1();
    vec3 N = it.normalVec;
    double LN = L.x*N.x + L.y*N.y + L.z*N.z;
    if(LN < 0)
        LN = -LN;
    Id *= LN;

    colour Is;
    double Ks = it.Ks;
    if(Ks < 0.1)
        Ks += 0.15;
    vec3 R = CalcReflect(L,N);
    R.setModule1();
    vec3 V = _start - it.pos;
    V.setModule1();
    double RV = R.x*V.x + R.y*V.y + R.z*V.z ;
    if(RV < 0)
        RV = -RV;
    Is =  lmp.Ip ;
    Is *= Ks;
    int n=5;
    for(int i=0;i<n;i++)
        Is *= RV;//暂时取n=2
//    Is *= RV;




    I = Id + Is + Ie;
    I *= shadowminus;

    I.Confine();
    return I;
}

vec3 RayTracer::CalcReflect(vec3 lt,vec3 normalv)
{
    vec3 n =normalv;
    vec3 l = lt;
    double ln = l.x*n.x + l.y*n.y + l.z*n.z;
    vec3 r;

    n *= ln;
    n *= 2;
    r = n - l;
    return r;
}

vec3 RayTracer::CalcZheshe(vec3 lt,intersection cp)
{
    vec3 I = lt;
    vec3 n = cp.normalVec;
    vec3 T;
    vec3 TN;
    double IN;
    double cos0T;
    double cos0i;
    double eta = cp.eta;

    T = I;
    T *= -(1/eta);

    IN = I.x*n.x + I.y*n.y + I.z*n.z;


    cos0i = IN;
    double tmp = 1 - (1-cos0i*cos0i) / (eta*eta) ;
    if(tmp > 0)
        cos0T = sqrt(tmp);
    else
        return CalcReflect(I,n);

    IN /= eta;
    IN -= cos0T;

    TN = n*IN;

    T += TN;

    T.setModule1();
    return T;

}

double RayTracer::InShadow(intersection it,lightsource lmp)
{
    vec3 testpos = it.pos;
    vec3 dirTolmp = lmp.pos - testpos;
    dirTolmp.setModule1();

    intersection temp = _scene.findIntersection(testpos,dirTolmp);
    if(temp.dis2start < 0 || temp.dis2start > testpos.Dis22(lmp.pos))//没有交点
    {
        return 1;
    }

    return (temp.Kt);

}
