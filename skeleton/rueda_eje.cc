#include "rueda_eje.h"

_rueda_eje::_rueda_eje(){}

void _rueda_eje::draw_point(){
    eje.draw_point();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,0.5,0);
    rueda1.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0.5,0);
    rueda2.draw_point();
    glPopMatrix();
}

void _rueda_eje::draw_line(){
    eje.draw_line();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,0.5,0);
    rueda1.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0.5,0);
    rueda2.draw_line();
    glPopMatrix();
}

void _rueda_eje::draw_fill(){
    eje.draw_fill();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,0.5,0);
    rueda1.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0.5,0);
    rueda2.draw_fill();
    glPopMatrix();
}

void _rueda_eje::draw_chess(){
    eje.draw_chess();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,0.5,0);
    rueda1.draw_chess();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0.5,0);
    rueda2.draw_chess();
    glPopMatrix();
}

void _rueda_eje::draw_lighted_flat_shading(){
    eje.draw_lighted_flat_shading();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,0.5,0);
    rueda1.draw_lighted_flat_shading();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0.5,0);
    rueda2.draw_lighted_flat_shading();
    glPopMatrix();
}

void _rueda_eje::draw_lighted_smooth_shading(){
    eje.draw_lighted_smooth_shading();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,0.5,0);
    rueda1.draw_lighted_smooth_shading();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0.5,0);
    rueda2.draw_lighted_smooth_shading();
    glPopMatrix();
}

void _rueda_eje::draw_texture(){
    eje.draw_texture();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,0.5,0);
    rueda1.draw_texture();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0.5,0);
    rueda2.draw_texture();
    glPopMatrix();
}