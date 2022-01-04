#include "Acompass.h"

_Acompass::_Acompass()
{
}

_Acompass::~_Acompass()
{
    Base.~_Abase();
    Arm.~_Aarm();
}

void _Acompass::draw_point()
{
    Base.draw_point();
    Arm.draw_point();
}

void _Acompass::draw_line()
{
    Base.draw_line();
    Arm.draw_line();
}

void _Acompass::draw_fill()
{
    Base.draw_fill();
    Arm.draw_fill();
}

void _Acompass::draw_chess()
{
    Base.draw_chess();
    Arm.draw_chess();
}

void _Acompass::draw_lighted_flat_shading()
{
    Base.draw_lighted_flat_shading();
    Arm.draw_lighted_flat_shading();
}

void _Acompass::draw_lighted_smooth_shading()
{
    Base.draw_lighted_smooth_shading();
    Arm.draw_lighted_smooth_shading();
}

void _Acompass::draw_texture()
{
    Base.draw_texture();
    Arm.draw_texture();
}

void _Acompass::update()
{
    Base.update();
    Arm.update();
}