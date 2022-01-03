#ifndef AARM_H
#define AARM_H

#include "cube.h"
#include "cilindro.h"
#include "Abase.h"
#include "math.h"

class _Aarm
{
private:
    _cube body;
    _Cilindro pivot1;
    _Cilindro pivot2;
    _Cilindro lpivot1;
    _Cilindro lpivot2;

    _Abase Base;

    //De 0 a PI

    float position_pivot1;
    float position_pivot2;
    
protected:
    bool direction_pivot1;
    bool direction_pivot2;

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
    void update(float _step=0.025);
};

#endif