#ifndef CUBE_H
#define CUBE_H

#include "object3d.h"

class _cube:public _object3D
{
public:
    _cube(float Size=1.0);

    void draw_texture();

private:
    vector<_vertex2f> cube_texture;

    GLfloat cube_texture_coordinates[72];
};

#endif // CUBE_H
