#ifndef AEND_H
#define AEND_H

#include "cube.h"
#include "cilindro.h"
#include "esfera.h"
#include "Abase.h"
#include "math.h"
#include "Atip.h"

class _Aend
{
private:
    _Esfera body;
    _Cilindro connection;

    _Atip pencil;

    float angulo;
    float position;

public:
    _Aend();
    ~_Aend();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_shading();
    void draw_lighted_smooth_shading();
    void draw_texture();
    
    void update(float _step=0.01);
};

#endif  // AEND_H