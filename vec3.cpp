#include "vec3.h"
#include<cmath>


vec3 operator + ( const vec3& A , const vec3& B )
{
    return vec3( A.x + B.x , A.y + B.y , A.z + B.z );
}

vec3 operator - ( const vec3& A , const vec3& B )
{
    return vec3( A.x - B.x , A.y - B.y , A.z - B.z );
}

vec3 operator * ( const vec3& A , const double& k )
{
    return vec3( A.x * k , A.y * k , A.z * k );
}

vec3 operator / ( const vec3& A , const double& k )
{
    return vec3( A.x / k , A.y / k , A.z / k );
}

vec3 operator * ( const vec3& A , const vec3& B )
{
    return vec3( A.y * B.z - A.z * B.y , A.z * B.x - A.x * B.z , A.x * B.y - A.y * B.x );
}

vec3& operator += ( vec3& A , const vec3& B )
{
    A = A + B;
    return A;
}

vec3& operator -= ( vec3& A , const vec3& B ) {
    A = A - B;
    return A;
}

vec3& operator *= ( vec3& A , const double& k )
{
    A = A * k;
    return A;
}

vec3& operator += ( vec3& A , const double& k )
{
    A = A / k;
    return A;
}

vec3& operator *= ( vec3& A , const vec3& B )
{
    A = A * B;
    return A;
}

vec3 operator - ( const vec3& A )
{
    return vec3( -A.x , -A.y , -A.z );
}

double vec3::Dis2zero()
{
    return sqrt( x * x + y * y + z * z );
}

double vec3::Dis2(vec3 & A)
{
    return ( A - *this ).Dis2zero();
}

double vec3::Dis2zero2()
{
    return ( x * x + y * y + z * z );
}

double vec3::Dis22(vec3 & A)
{
    return ( A - *this ).Dis2zero2();
}

void vec3::setModule1()
{
    double r = Dis2zero();
    x /= r;
    y /= r;
    z /= r;
}

void vec3::showinfo()
{
    qDebug()<<x<<" "<<y<<" "<<z<<endl;
}
