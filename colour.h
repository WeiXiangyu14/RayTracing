#ifndef COLOUR_H
#define COLOUR_H
#include <QDebug>

class colour
{
public:
    double r , g , b;

    colour( double R = 0 , double G = 0 , double B = 0 ) : r( R ) , g( G ) , b( B ) {}
    ~colour() {}

    friend colour operator + ( const colour& , const colour& );
    friend colour operator - ( const colour& , const colour& );
    friend colour operator * ( const colour& , const colour& );
    friend colour operator * ( const colour& , const double& );
    friend colour operator / ( const colour& , const double& );
    friend colour& operator += ( colour& , const colour& );
    friend colour& operator -= ( colour& , const colour& );
    friend colour& operator *= ( colour& , const double& );
    friend colour& operator /= ( colour& , const double& );
    void Confine(); //luminance must be less than or equal to 1
    void showinfo();
};

#endif // COLOUR_H
