#ifndef RUEDA_EJE_H
#define RUEDA_EJE_H

#include "rueda.h"
#include "eje.h"

class _rueda_eje:public _rueda, public _eje{
    public:
        _rueda_eje();
        _eje eje;
        _rueda rueda1;
        _rueda rueda2;

        void draw_point();
        void draw_line();
        void draw_fill();
        void draw_chess();
        void draw_lighted_flat_shading();
        void draw_lighted_smooth_shading();
        void draw_texture();
};

#endif