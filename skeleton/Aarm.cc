#include "Aarm.h"

_Aarm::_Aarm()
{
    position_pivot1 = M_PI;
    position_pivot2 = -M_PI;
}

_Aarm::~_Aarm()
{
    Base.~_Abase();
    body.~_cube();
    pivot1.~_Cilindro();
    pivot2.~_Cilindro();
}

void _Aarm::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(cosposition1, 0, 0);
    glScalef(0.2, 0.1, 0.2);
    pivot1.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cosposition1, 0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    lpivot1.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, sinposition2);
    glScalef(0.2, 0.1, 0.2);
    pivot2.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glScalef(0.05, 0.2, 0.05);
    lpivot2.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, 0.95);
    glScalef(0.1, 0.1, 2);
    body.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, headposition);
    End.draw_point();
    glPopMatrix();   
}

void _Aarm::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(cosposition1, 0, 0);
    glScalef(0.2, 0.1, 0.2);
    pivot1.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cosposition1, 0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    lpivot1.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, sinposition2);
    glScalef(0.2, 0.1, 0.2);
    pivot2.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glScalef(0.05, 0.2, 0.05);
    lpivot2.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, 0.95);
    glScalef(0.1, 0.1, 2);
    body.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, headposition);
    End.draw_line();
    glPopMatrix();
}

void _Aarm::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(cosposition1, 0, 0);
    glScalef(0.2, 0.1, 0.2);
    pivot1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cosposition1, 0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    lpivot1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, sinposition2);
    glScalef(0.2, 0.1, 0.2);
    pivot2.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glScalef(0.05, 0.2, 0.05);
    lpivot2.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, 0.95);
    glScalef(0.1, 0.1, 2);
    body.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, headposition);
    End.draw_fill();
    glPopMatrix();
}

void _Aarm::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(cosposition1, 0, 0);
    glScalef(0.2, 0.1, 0.2);
    pivot1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cosposition1, 0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    lpivot1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, sinposition2);
    glScalef(0.2, 0.1, 0.2);
    pivot2.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glScalef(0.05, 0.2, 0.05);
    lpivot2.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, 0.95);
    glScalef(0.1, 0.1, 2);
    body.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, headposition);
    End.draw_chess();
    glPopMatrix();
}

void _Aarm::draw_lighted_flat_shading()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(cosposition1, 0, 0);
    glScalef(0.2, 0.1, 0.2);
    pivot1.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cosposition1, 0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    lpivot1.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, sinposition2);
    glScalef(0.2, 0.1, 0.2);
    pivot2.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glScalef(0.05, 0.2, 0.05);
    lpivot2.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, 0.95);
    glScalef(0.1, 0.1, 2);
    body.draw_lighted_flat_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, headposition);
    End.draw_lighted_flat_shading();
    glPopMatrix();
}

void _Aarm::draw_lighted_smooth_shading()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(cosposition1, 0, 0);
    glScalef(0.2, 0.1, 0.2);
    pivot1.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cosposition1, 0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    lpivot1.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, sinposition2);
    glScalef(0.2, 0.1, 0.2);
    pivot2.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glScalef(0.05, 0.2, 0.05);
    lpivot2.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, 0.95);
    glScalef(0.1, 0.1, 2);
    body.draw_lighted_smooth_shading();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, headposition);
    End.draw_lighted_smooth_shading();
    glPopMatrix();
}

void _Aarm::draw_texture()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(cosposition1, 0, 0);
    glScalef(0.2, 0.1, 0.2);
    pivot1.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cosposition1, 0.1, 0);
    glScalef(0.05, 0.2, 0.05);
    lpivot1.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, sinposition2);
    glScalef(0.2, 0.1, 0.2);
    pivot2.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glScalef(0.05, 0.2, 0.05);
    lpivot2.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, 0.95);
    glScalef(0.1, 0.1, 2);
    body.draw_texture();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.1, sinposition2);
    glRotated(angulo, 0, 1, 0);
    glTranslated(0, 0, headposition);
    End.draw_texture();
    glPopMatrix();
}

void _Aarm::update(float _step)
{
    position_pivot1 += _step;
    position_pivot2 += _step;
    if (position_pivot1 >= M_PI)
    {
        position_pivot1 = -M_PI;
    }
    if (position_pivot2 >= M_PI)
    {
        position_pivot2 = -M_PI;
    }
    angulo = -atan(cos(position_pivot1) / sin(position_pivot2)) * (180 / M_PI);
    if (position_pivot2 > 0)
    {
        angulo += 180;
    }
    cosposition1 = cos(position_pivot1) / 2;
    sinposition2 = sin(position_pivot2) / 2;
    headposition = 1.5 + cosposition1;
    End.update();
}