#ifndef ANIMATIONFRAME_H
#define ANIMATIONFRAME_H

#include "vertex.h"

class AnimationFrame
{
    private:
        int steps, currentstep;

        bool loop;

        _vertex3f initposition;
        float initrotation;
        float initscale;
        
        _vertex3f endposition;
        float endrotation;
        float endscale;

        _vertex3f currentposition;
        float currentrotation; 
        float currentscale;
    
    public:
        AnimationFrame();
        ~AnimationFrame();

        void setSteps(int steps);
        void setLoop(bool loop);

        void setInitPosition(_vertex3f _position);
        void setInitRotation(float _rotation);
        void setInitScale(float _scale);

        void setEndPosition(_vertex3f _position);
        void setEndRotation(float _rotation);
        void setEndScale(float _scale);

        _vertex3f getCurrentPosition();
        float getCurrentRotation();
        float getCurrentScale();

        void update();

        bool isFinished();

        void reset();

        bool islooped();
};

#endif