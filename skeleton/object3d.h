/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

class _object3D : public _basic_object3D
{
public:
	vector<int> num_normales;
	vector<_vertex3f> Vertices_normals;
	vector<_vertex3ui> Triangles;
	vector<_vertex3f> Triangles_normals;
	
	vector<_vertex2f> texture_coordinates;
	vector<_vertex2f> Vertices_texture_coordinates;

	void draw_line();
	void draw_fill();
	void draw_chess();
	void draw_lighted_flat_shading();
	void draw_lighted_smooth_shading();
	void draw_texture();

	void Translate(_vertex3f _vector);
	void Rotate(float _angle);
	void Resize(float _factor);
	void compute_triangles_normals();
	void compute_vertices_normals();
};

#endif // OBJECT3D_H
