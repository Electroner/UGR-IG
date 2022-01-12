#ifndef ACOMPASS_H
#define ACOMPASS_H

#include "Aarm.h"
#include "Abase.h"

class _Acompass
{
private:
    _Abase Base;
    _Aarm Arm;
    
public:

    _Acompass();
    ~_Acompass();

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