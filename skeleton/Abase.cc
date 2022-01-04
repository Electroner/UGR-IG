#include "Abase.h"

_Abase::_Abase(){}

_Abase::~_Abase(){}

void _Abase::draw_point(){

}

void _Abase::draw_line(){

}

void _Abase::draw_fill(){

}

void _Abase::draw_chess(){

}

void _Abase::draw_lighted_flat_shading(){

}

void _Abase::draw_lighted_smooth_shading(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glScalef(1,0.1,1);
    base.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    a.draw_lighted_smooth_shading();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    b.draw_lighted_smooth_shading();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    c.draw_lighted_smooth_shading();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    d.draw_lighted_smooth_shading();
    glPopMatrix();
}

void _Abase::draw_texture(){

}

void _Abase::update(){

}