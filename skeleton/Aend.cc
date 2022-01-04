#include "Aend.h"

_Aend::_Aend(){
    position = M_PI/2;
}

_Aend::~_Aend(){
    body.~_Esfera();
    connection.~_Cilindro();
    pencil.~_Atip();
}

void _Aend::draw_point(){
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    body.draw_point();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glTranslatef(0.2, 0, 0);
    pencil.draw_point();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glRotated(90,0,0,1);
    glTranslated(0, -0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    connection.draw_point();
    glPopMatrix();
}

void _Aend::draw_line(){
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    body.draw_line();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glTranslatef(0.2, 0, 0);
    pencil.draw_line();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glRotated(90,0,0,1);
    glTranslated(0, -0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    connection.draw_line();
    glPopMatrix();
}

void _Aend::draw_fill(){
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    body.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glTranslatef(0.2, 0, 0);
    pencil.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glRotated(90,0,0,1);
    glTranslated(0, -0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    connection.draw_fill();
    glPopMatrix();
}

void _Aend::draw_chess(){
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    body.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glTranslatef(0.2, 0, 0);
    pencil.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glRotated(90,0,0,1);
    glTranslated(0, -0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    connection.draw_chess();
    glPopMatrix();
}

void _Aend::draw_lighted_flat_shading(){
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    body.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glTranslatef(0.2, 0, 0);
    pencil.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glRotated(90,0,0,1);
    glTranslated(0, -0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    connection.draw_lighted_flat_shading();
    glPopMatrix();
}

void  _Aend::draw_lighted_smooth_shading(){
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    body.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glTranslatef(0.2, 0, 0);
    pencil.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glRotated(90,0,0,1);
    glTranslated(0, -0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    connection.draw_lighted_smooth_shading();
    glPopMatrix();
}

void _Aend::draw_texture(){
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    body.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glTranslatef(0.2, 0, 0);
    pencil.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo,0,0,1);
    glRotated(90,0,0,1);
    glTranslated(0, -0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    connection.draw_texture();
    glPopMatrix();
}

void  _Aend::update(){
    angulo = cos(position)*90;
    position -= 0.01;
    if(position <= -M_PI/2){
        position = M_PI/2;
    }
}