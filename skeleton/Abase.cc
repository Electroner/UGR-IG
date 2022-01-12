#include "Abase.h"

_Abase::_Abase(){}

_Abase::~_Abase(){}

void _Abase::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glScalef(1,0.1,1);
    base.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    a.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    b.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    c.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    d.draw_point();
    glPopMatrix();
}

void _Abase::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glScalef(1,0.1,1);
    base.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    a.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    b.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    c.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    d.draw_line();
    glPopMatrix();
}

void _Abase::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glScalef(1,0.1,1);
    base.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    a.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    b.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    c.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    d.draw_fill();
    glPopMatrix();
}

void _Abase::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glScalef(1,0.1,1);
    base.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    a.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    b.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    c.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    d.draw_chess();
    glPopMatrix();
}

void _Abase::draw_lighted_flat_shading(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glScalef(1,0.1,1);
    base.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    a.draw_lighted_flat_shading();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    b.draw_lighted_flat_shading();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    c.draw_lighted_flat_shading();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    d.draw_lighted_flat_shading();
    glPopMatrix();
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
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glScalef(1,0.1,1);
    base.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    a.draw_texture();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, 0.3);
    glScalef(0.4,0.1,0.4);
    b.draw_texture();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    c.draw_texture();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 0, -0.3);
    glScalef(0.4,0.1,0.4);
    d.draw_texture();
    glPopMatrix();
}

void _Abase::update(float _step){

}