#include "colour.h"

colour operator + ( const colour& A , const colour& B )
{
    return colour( A.r + B.r , A.g + B.g , A.b + B.b );
}

colour operator - ( const colour& A , const colour& B )
{
    return colour( A.r - B.r , A.g - B.g , A.b - B.b );
}

colour operator * ( const colour& A , const colour& B )
{
    return colour( A.r * B.r , A.g * B.g , A.b * B.b );
}

colour operator * ( const colour& A , const double& k )
{
    return colour( A.r * k , A.g * k , A.b * k );
}

colour operator / ( const colour& A , const double& k )
{
    return colour( A.r / k , A.g / k , A.b / k );
}

colour& operator += ( colour& A , const colour& B )
{
    A = A + B;
    return A;
}

colour& operator -= ( colour& A , const colour& B )
{
    A = A - B;
    return A;
}

colour& operator *= ( colour& A , const double& k )
{
    A = A * k;
    return A;
}

colour& operator /= ( colour& A , const double& k )
{
    A = A / k;
    return A;
}

void colour::Confine()
{
    if ( r > 255 )
        r = 255;
    if ( g > 255 )
        g = 255;
    if ( b > 255 )
        b = 255;
}

void colour::showinfo()
{
    qDebug()<<"r:"<<r<<" g:"<<g<<" b:"<<b<<endl;
}
