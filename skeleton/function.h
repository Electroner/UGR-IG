#ifndef FUNCTION_H
#define FUNCTION_H

#include <math.h>

inline float RevFuncitonFX(float _x)
{
    return ((sqrt(abs(_x)+0.25))/cos(_x));
}

#endif // FUNCTION_H
