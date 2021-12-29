#ifndef FUNCTION_H
#define FUNCTION_H

#include <math.h>

inline float RevFuncitonFX(float _x)
{
    return ((sqrt(abs(_x)+1))/cos(_x));
}

#endif // FUNCTION_H
