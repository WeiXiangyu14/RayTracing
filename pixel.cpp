#include "pixel.h"

pixel::pixel()
{

}

pixel::~pixel()
{

}

void pixel::resetcamera(vec3 c)
{
    camera = c;
}

void pixel::resetpos(vec3 p)
{
    pos = p;
}

void pixel::resetcolour(colour cl)
{
    pcolour = cl;
}
