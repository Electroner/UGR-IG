#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "object3d.h"
#include "cube.h"

class _chess_board : public _object3D
{
private:
	unsigned int divisions;
	vector<_vertex2f> texture_coordinates;
	_cube board;

public:
	_chess_board(float Size = 1.0, unsigned int Divisions1 = 1);

    void draw_texture();
};

#endif