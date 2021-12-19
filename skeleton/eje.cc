#include "eje.h"

_eje::_eje(){}

void _eje::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
    glScalef(0.1,1.75,0.1);
    eje.draw_point();
    glPopMatrix();
}

void _eje::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
    glScalef(0.1,1.75,0.1);
    eje.draw_line();
    glPopMatrix();
}

void _eje::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
    glScalef(0.1,1.75,0.1);
    eje.draw_fill();
    glPopMatrix();
}

void _eje::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
    glScalef(0.1,1.75,0.1);
    eje.draw_chess();
    glPopMatrix();
}

void _eje::draw_lighted_flat_shading(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
    glScalef(0.1,1.75,0.1);
    eje.draw_lighted_flat_shading();
    glPopMatrix();
}

void _eje::draw_lighted_smooth_shading(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
    glScalef(0.1,1.75,0.1);
    eje.draw_lighted_smooth_shading();
    glPopMatrix();
}

void _eje::draw_texture(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
    glScalef(0.1,1.75,0.1);
    eje.draw_texture();
    glPopMatrix();
}