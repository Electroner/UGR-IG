#ifndef AARM_H
#define AARM_H

#include "cube.h"
#include "cilindro.h"

class _Aarm
{
private:
    _cube body;
    _Cilindro pivot1;
    _Cilindro pivot2;

public:
    _Aarm();
    ~_Aarm();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_shading();
    void draw_lighted_smooth_shading();
    void draw_texture();
};

#endif