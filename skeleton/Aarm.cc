#include "Aarm.h"
#include <iostream>
_Aarm::_Aarm(){
    position_pivot1 = M_PI;
    position_pivot2 = 0;
    direction_pivot1 = true;
    direction_pivot2 = true;
}

_Aarm::~_Aarm(){
    Base.~_Abase();
    body.~_cube();
    pivot1.~_Cilindro();
    pivot2.~_Cilindro();
}

void _Aarm::draw_point(){

}

void _Aarm::draw_line(){

}

void _Aarm::draw_fill(){

}

void _Aarm::draw_chess(){

}

void _Aarm::draw_lighted_flat_shading(){

}

void _Aarm::draw_lighted_smooth_shading(){
    Base.draw_lighted_smooth_shading();
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    glTranslatef(cos(position_pivot1)/2, 0, 0);
    glScalef(0.2,0.1,0.2);
    pivot1.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cos(position_pivot1)/2, 0.1, 0);
    glScalef(0.05,0.2,0.05);
    lpivot1.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, sin(position_pivot2)/2);
    glScalef(0.2,0.1,0.2);
    pivot2.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sin(position_pivot2)/2);
    glScalef(0.05,0.2,0.05);
    lpivot2.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sin(position_pivot2)/2);
    glRotated(cos(position_pivot1)*90, 0, 1, 0);
    glTranslated(0,0,0.95);
    glScalef(0.1,0.1,2);
    body.draw_lighted_smooth_shading();
    glPopMatrix();

    cout<<"position_pivot1: "<<position_pivot1<<endl;
    cout<<"position_pivot2: "<<position_pivot2<<endl;
    cout<<"pivot1 cos"<< cos(position_pivot1)<<endl;
    cout<<"pivot2 sin"<< sin(position_pivot2)<<endl;
}

void _Aarm::draw_texture(){

}

void _Aarm::update(float _step){
    if(direction_pivot1){
        position_pivot1 -= _step;
        if(position_pivot1 >= M_PI){
            direction_pivot1 = false;
        }
    }else{
        position_pivot1 += _step;
        if(position_pivot1 <= 0){
            direction_pivot1 = true;
        }
    }
    if(direction_pivot2){
        position_pivot2 -= _step;
        if(position_pivot2 >= M_PI){
            direction_pivot2 = false;
        }
    }else{
        position_pivot2 += _step;
        if(position_pivot2 <= 0){
            direction_pivot2 = true;
        }
    }
}