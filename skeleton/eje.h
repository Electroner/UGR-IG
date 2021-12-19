#ifndef EJE_H
#define EJE_H

#include "cilindro.h"

class _eje : public _Cilindro
{
	public:
		_eje();
		_Cilindro eje{10};
	
		void draw_point();
		void draw_line();
		void draw_fill();
		void draw_chess();
		void draw_lighted_flat_shading();
		void draw_lighted_smooth_shading();
};

#endif