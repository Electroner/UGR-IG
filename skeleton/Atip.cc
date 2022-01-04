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
    glPushMatrix();
    glTranslatef(0, -0.25, 0);
    glScalef(0.1,0.1,0.1);
    Tip.draw_point();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.05,0.3,0.05);
    Pencil.draw_point();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.075,0.075,0.075);
    Joint.draw_point();
    glPopMatrix();
}

void  _Atip::draw_line(){
    glPushMatrix();
    glTranslatef(0, -0.25, 0);
    glScalef(0.1,0.1,0.1);
    Tip.draw_line();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.05,0.3,0.05);
    Pencil.draw_line();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.075,0.075,0.075);
    Joint.draw_line();
    glPopMatrix();
}

void  _Atip::draw_fill(){
    glPushMatrix();
    glTranslatef(0, -0.25, 0);
    glScalef(0.1,0.1,0.1);
    Tip.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.05,0.3,0.05);
    Pencil.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.075,0.075,0.075);
    Joint.draw_fill();
    glPopMatrix();
}

void _Atip::draw_chess(){
    glPushMatrix();
    glTranslatef(0, -0.25, 0);
    glScalef(0.1,0.1,0.1);
    Tip.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.05,0.3,0.05);
    Pencil.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.075,0.075,0.075);
    Joint.draw_chess();
    glPopMatrix();
}

void _Atip::draw_lighted_flat_shading(){
    glPushMatrix();
    glTranslatef(0, -0.25, 0);
    glScalef(0.1,0.1,0.1);
    Tip.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.05,0.3,0.05);
    Pencil.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.075,0.075,0.075);
    Joint.draw_lighted_flat_shading();
    glPopMatrix();
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
    glPushMatrix();
    glTranslatef(0, -0.25, 0);
    glScalef(0.1,0.1,0.1);
    Tip.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.05,0.3,0.05);
    Pencil.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.075,0.075,0.075);
    Joint.draw_texture();
    glPopMatrix();
}

void _Atip::update(){

}