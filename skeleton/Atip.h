#ifndef ATIP_H
#define ATIP_H

#include "cube.h"
#include "cilindro.h"
#include "esfera.h"
#include "Abase.h"
#include "math.h"
#include "function.h"

class _Atip
{
private:
    _Esfera Body;
    _Cilindro Joint;
    _Cilindro Pencil;
    _revOBJ Tip;

public:

    _Atip();
    ~_Atip();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_shading();
    void draw_lighted_smooth_shading();
    void draw_texture();

    void update(float _step=0.01);
};

#endif