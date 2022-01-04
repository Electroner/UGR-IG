#include "Atip.h"

_Atip::_Atip(){
    Tip.function_revobj(&RevFuncitonFX, -1, 1, 0.01, 180, true, true);
}

_Atip::~_Atip(){
    Joint.~_Cilindro();
    Pencil.~_Cilindro();
    Tip.~_revOBJ();
}

void  _Atip::draw_point(){

}

void  _Atip::draw_line(){

}

void  _Atip::draw_fill(){

}

void _Atip::draw_chess(){

}

void _Atip::draw_lighted_flat_shading(){

}

void _Atip::draw_lighted_smooth_shading(){
    glPushMatrix();
    glTranslatef(0, -0.25, 0);
    glScalef(0.1,0.1,0.1);
    Tip.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.05,0.3,0.05);
    Pencil.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.075,0.075,0.075);
    Joint.draw_lighted_smooth_shading();
    glPopMatrix();
}

void _Atip::draw_texture(){

}

void _Atip::update(){

}