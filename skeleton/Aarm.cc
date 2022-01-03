#include "Aarm.h"

_Aarm::_Aarm(){}

_Aarm::~_Aarm(){}

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
}

void _Aarm::draw_texture(){

}

void _Aarm::update(){
    if(direction_pivot1){
        position_pivot1 -= 0.05;
        if(position_pivot1 >= M_PI){
            direction_pivot1 = false;
        }
    }else{
        position_pivot1 += 0.05;
        if(position_pivot1 <= 0){
            direction_pivot1 = true;
        }
    }
}