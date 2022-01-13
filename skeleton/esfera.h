#ifndef ESFERA_H
#define ESFERA_H

#include "revobj.h"

class _Esfera:public _revOBJ{

    private:
        float round(float x, int d);

    public:
        _Esfera();
        _Esfera(int n);
        _Esfera(int n,int k);
};

#endif
