#include "animationframe.h"

AnimationFrame::AnimationFrame()
{
    steps = 0;
    currentstep = 0;
    loop = false;
    initposition = _vertex3f(0,0,0);
    initrotation = 0;
    initscale = 1;
    endposition = _vertex3f(0,0,0);
    endrotation = 0;
    endscale = 1;
    currentposition = _vertex3f(0,0,0);
    currentrotation = 0;
    currentscale = 1;
}

AnimationFrame::~AnimationFrame()
{
}

void AnimationFrame::setSteps(int _steps)
{
    steps = _steps;
}

void AnimationFrame::setLoop(bool _loop)
{
    loop = _loop;
}

void AnimationFrame::setInitPosition(_vertex3f _position)
{
    initposition = _position;
}

void AnimationFrame::setInitRotation(float _rotation)
{
    initrotation = _rotation;
}

void AnimationFrame::setInitScale(float _scale)
{
    initscale = _scale;
}

void AnimationFrame::setEndPosition(_vertex3f _position)
{
    endposition = _position;
}   

void AnimationFrame::setEndRotation(float _rotation)
{
    endrotation = _rotation;
}   

void AnimationFrame::setEndScale(float _scale)
{
    endscale = _scale;
}   

_vertex3f AnimationFrame::getCurrentPosition()
{
    return currentposition;
}

float AnimationFrame::getCurrentRotation()
{
    return currentrotation;
}

float AnimationFrame::getCurrentScale()
{
    return currentscale;
}

void AnimationFrame::update()
{
    if(currentstep < steps)
    {
        currentposition = initposition + (endposition - initposition) * currentstep / steps;
        currentrotation = initrotation + (endrotation - initrotation) * currentstep / steps;
        currentscale = initscale + (endscale - initscale) * currentstep / steps;
        currentstep++;
    }
    else
    {
        if(loop)
        {
            currentstep = 0;
            update();
        }
    }
}

bool AnimationFrame::isFinished()
{
    if(currentstep >= steps)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void AnimationFrame::reset()
{
    currentstep = 0;
}

bool AnimationFrame::islooped()
{
    return loop;
}
 