/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QImage>
#include <QImageReader>
#include <iostream>
#include <QInputDialog>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "plyobj.h"
#include "revobj.h"
#include "cilindro.h"
#include "esfera.h"
#include "rueda.h"
#include "eje.h"
#include "rueda_eje.h"
#include "function.h"
#include "chess_board.h"
#include "Abase.h"
#include "Aarm.h"
#include "Atip.h"
#include "Aend.h"
#include "Acompass.h"

namespace _gl_widget_ne
{

	const float X_MIN = -.1;
	const float X_MAX = .1;
	const float Y_MIN = -.1;
	const float Y_MAX = .1;
	const float FRONT_PLANE_PERSPECTIVE = (X_MAX - X_MIN) / 2;
	const float BACK_PLANE_PERSPECTIVE = 1000;
	const float DEFAULT_DISTANCE = 2;
	const float ANGLE_STEP = 1;

	typedef enum
	{
		MODE_DRAW_POINT,
		MODE_DRAW_LINE,
		MODE_DRAW_FILL,
		MODE_DRAW_CHESS,
		MODE_ILLUMINATION_FLAT_SHADING
	} _mode_draw;
	typedef enum
	{
		OBJECT_TETRAHEDRON,
		OBJECT_CUBE,
		OBJECT_PLY,
		OBJECT_REV,
		OBJECT_CILINDRO,
		OBJECT_SPHERE,
		OBJECT_REVFX,
		OBJECT_WHEEL,
		OBJECT_EJE,
		OBJECT_RUEDA_EJE,
		OBJECT_CHESS_BOARD,
		OBJECT_COMPASS,
		OBJECT_ARM,
		OBJECT_END,
		OBJECT_TIP,
		OBJECT_BASE
	} _object;
}

class _window;

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
	Q_OBJECT
public:
	_gl_widget(_window *Window1);

	void clear_window();
	void change_projection();
	void change_observer();

	void draw_axis();
	void draw_objects();
	void build_lights();
	void build_material(string _material);

	void set_animation();

protected:
	void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
	void paintGL() Q_DECL_OVERRIDE;
	void initializeGL() Q_DECL_OVERRIDE;
	void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
	//void mousePressEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  	//void mouseReleaseEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  	void mouseMoveEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  	void wheelEvent(QWheelEvent *Event) Q_DECL_OVERRIDE;

protected slots:
	void tick();

private:
	_window *Window;

	_chess_board chess_board{0.5,8};
	_axis Axis;
	_tetrahedron Tetrahedron;
	_cube Cube;
	_plyObj plyobj;
	_revOBJ revOBJ{vector<_vertex3f>{_vertex3f(0, -0.5, 0), _vertex3f(0.5, -0.5, 0), _vertex3f(0, 0.5, 0)}, 10};
	_Cilindro Cilindro;
	_Esfera sphereOBJ{40,40};
	_revOBJ revFX;

	_rueda wheel;
	_eje eje;
	_rueda_eje rueda_eje;

	_Acompass Compass;
	_Aarm Arm;
	_Aend End;
	_Atip Tip;
	_Abase Base;

	_gl_widget_ne::_object Object;

	QImage Image; //Textura

	QTimer *Timer;

	bool Draw_point;
	bool Draw_line;
	bool Draw_fill;
	bool Draw_chess;
	bool Draw_flat_shading;
	bool Draw_smooth_shading;
	bool Draw_texture;
	bool Draw_axis;

	bool Translate;

	float Observer_angle_x;
	float Observer_angle_y;
	float Observer_distance;

	bool animation;

	bool light0_enabled;
	bool light1_enabled;
	string material;
	int angle_ligth;

	bool perspective; //TRUE = PERSPECTIVE, FALSE = ORTHO
	float reduction = 0.1;

	float last_x;	//CONTROL RELATIVE POSITION MOUASE
	float last_y;	
};

#endif
