#ifndef VEC3_H
#define VEC3_H
#include<cmath>
#include<cstring>
#include "const.h"

class vec3
{
public:
    vec3(double xx = 0 , double yy = 0 , double zz = 0): x( xx ) , y( yy ) , z( zz ) {}
    ~vec3(){}
    friend vec3 operator + ( const vec3& , const vec3& );
    friend vec3 operator - ( const vec3& , const vec3& );
    friend vec3 operator * ( const vec3& , const double& );
    friend vec3 operator / ( const vec3& , const double& );
    friend vec3 operator * ( const vec3& , const vec3& ); //cross product
    friend vec3& operator += ( vec3& , const vec3& );
    friend vec3& operator -= ( vec3& , const vec3& );
    friend vec3& operator *= ( vec3& , const double& );
    friend vec3& operator /= ( vec3& , const double& );
    friend vec3& operator *= ( vec3& , const vec3& );
    friend vec3 operator - ( const vec3& );

    double Dis2zero();
    double Dis2( vec3& );
    double Dis2zero2();
    double Dis22( vec3& );
    void setModule1();
    void showinfo();

//    double Dot( const vec3& );
//    double Distance( vec3& );
//    double& GetCoord( int axis );
//    vec3 GetUnitVector();
//    void AssRandomVector();
//    vec3 GetAnVerticalVector();
//    bool IsZeroVector();
//    void Input( std::stringstream& fin );
//    vec3 Reflect( vec3 N );
//    vec3 Refract( vec3 N , double n );
//    vec3 Diffuse();
//    vec3 Rotate( vec3 axis , double theta );
    double x, y, z;
};

#endif // VEC3_H
