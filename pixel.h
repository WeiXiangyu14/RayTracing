#ifndef PIXEL_H
#define PIXEL_H
#include "vec3.h"
#include "colour.h"

class pixel
{
public:
    pixel();
    ~pixel();
    void resetcamera(vec3 c);
    void resetpos(vec3 p);
    void resetcolour(colour cl);
    vec3 camera;
    vec3 pos;
    colour pcolour;
};

#endif // PIXEL_H
