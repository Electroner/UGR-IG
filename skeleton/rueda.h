#ifndef RUEDA_H
#define RUEDA_H

#include "cilindro.h"

class _rueda:public _Cilindro{

    public:
        _rueda();
        _Cilindro Rueda{50};

        void draw_point();
        void draw_line();
        void draw_fill();
        void draw_chess();
        void draw_lighted_flat_shading();
        void draw_lighted_smooth_shading();
        void draw_texture();
};

#endif
