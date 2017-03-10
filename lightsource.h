#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include "vec3.h"
#include "colour.h"

class lightsource
{
public:
    lightsource();
    ~lightsource();
    colour Ip;
    vec3 pos;

};

#endif // LIGHTSOURCE_H
