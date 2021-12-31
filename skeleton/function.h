#ifndef FUNCTION_H
#define FUNCTION_H

#include <math.h>

//EJEMPLO DE USO FUNCION HAACK SERIES NOSE CONE: https://en.wikipedia.org/wiki/Nose_cone_design#Haack_series
//EJEMPLO DE Von Kármán

const float C_NOSECONE = 0.0;
const float L_NOSECONE = 1.0;
const float R_NOSECONE = 0.3;

inline float RevFuncitonFX(float _x)
{
    float Theta = acos((1-((2*(_x))/(L_NOSECONE))));
    return ((R_NOSECONE/(sqrt(M_PI)))*(sqrt(Theta-((sin(2*Theta)/2))+(C_NOSECONE*pow(sin(Theta),3)))));
}

#endif // FUNCTION_H
