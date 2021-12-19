#ifndef PLYOBJ_H
#define PLYOBJ_H
#include "object3d.h"

class _plyObj:public _object3D
{
    private:
    void construct(const string name);
public:
    _plyObj();
    _plyObj(const string name);
    void File(const string name);
};

#endif // PLYOBJ_H
