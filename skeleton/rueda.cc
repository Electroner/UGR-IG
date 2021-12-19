#include "rueda.h"

_rueda::_rueda(){}

void _rueda::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,1,1);
    glRotatef(90,0,1,0);
    Rueda.draw_point();
    glPopMatrix();
}

void _rueda::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,1,1);
    glRotatef(90,0,1,0);
    Rueda.draw_line();
    glPopMatrix();
}

void _rueda::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,1,1);
    glRotatef(90,0,1,0);
    Rueda.draw_fill();
    glPopMatrix();
}

void _rueda::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,1,1);
    glRotatef(90,0,1,0);
    Rueda.draw_chess();
    glPopMatrix();
}

void _rueda::draw_lighted_flat_shading(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,1,1);
    glRotatef(90,0,1,0);
    Rueda.draw_lighted_flat_shading();
    glPopMatrix();
}

void _rueda::draw_lighted_smooth_shading(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,1,1);
    glRotatef(90,0,1,0);
    Rueda.draw_lighted_smooth_shading();
    glPopMatrix();
}

void _rueda::draw_texture(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,1,1);
    glRotatef(90,0,1,0);
    Rueda.draw_texture();
    glPopMatrix();
}