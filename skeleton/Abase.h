#ifndef ABASE_H
#define ABASE_H

#include "cube.h"

class _Abase
{
private:
    _cube a;
    _cube b;
    _cube c;
    _cube d;
    _cube base1;
    _cube base2;
    _cube base3;
    _cube base4;

public:
    _Abase();
    ~_Abase();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_shading();
    void draw_lighted_smooth_shading();
    void draw_texture();
};

#endif