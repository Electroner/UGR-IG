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
#include "rueda.h"
#include "eje.h"
#include "rueda_eje.h"
#include "function.h"
#include "chess_board.h"

namespace _gl_widget_ne
{

	const float X_MIN = -.1;
	const float X_MAX = .1;
	const float Y_MIN = -.1;
	const float Y_MAX = .1;
	const float FRONT_PLANE_PERSPECTIVE = (X_MAX - X_MIN) / 2;
	const float BACK_PLANE_PERSPECTIVE = 1000;
	const float FRONT_PLANE_ORTHO=-5000;
  	const float BACK_PLANE_ORTHO=5000;
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
		OBJECT_CHESS_BOARD
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
	_revOBJ sphereOBJ{vector<_vertex3f>{_vertex3f(0,-0.5,0),_vertex3f(0,-0.499924,0.0087262),_vertex3f(0,-0.499695,0.0174497),_vertex3f(0,-0.499315,0.026168),_vertex3f(0,-0.498782,0.0348782),_vertex3f(0,-0.498097,0.0435779),_vertex3f(0,-0.497261,0.0522642),_vertex3f(0,-0.496273,0.0609347),_vertex3f(0,-0.495134,0.0695866),_vertex3f(0,-0.493844,0.0782172),_vertex3f(0,-0.492404,0.0868241),_vertex3f(0,-0.490814,0.0954045),_vertex3f(0,-0.489074,0.103956),_vertex3f(0,-0.487185,0.112476),_vertex3f(0,-0.485148,0.120961),_vertex3f(0,-0.482963,0.12941),_vertex3f(0,-0.480631,0.137819),_vertex3f(0,-0.478152,0.146186),_vertex3f(0,-0.475528,0.154509),_vertex3f(0,-0.472759,0.162784),_vertex3f(0,-0.469846,0.17101),_vertex3f(0,-0.46679,0.179184),_vertex3f(0,-0.463592,0.187303),_vertex3f(0,-0.460252,0.195366),_vertex3f(0,-0.456773,0.203368),_vertex3f(0,-0.453154,0.211309),_vertex3f(0,-0.449397,0.219186),_vertex3f(0,-0.445503,0.226995),_vertex3f(0,-0.441474,0.234736),_vertex3f(0,-0.43731,0.242405),_vertex3f(0,-0.433013,0.25),_vertex3f(0,-0.428584,0.257519),_vertex3f(0,-0.424024,0.26496),_vertex3f(0,-0.419335,0.27232),_vertex3f(0,-0.414519,0.279596),_vertex3f(0,-0.409576,0.286788),_vertex3f(0,-0.404509,0.293893),_vertex3f(0,-0.399318,0.300908),_vertex3f(0,-0.394005,0.307831),_vertex3f(0,-0.388573,0.31466),_vertex3f(0,-0.383022,0.321394),_vertex3f(0,-0.377355,0.32803),_vertex3f(0,-0.371572,0.334565),_vertex3f(0,-0.365677,0.340999),_vertex3f(0,-0.35967,0.347329),_vertex3f(0,-0.353553,0.353553),_vertex3f(0,-0.347329,0.35967),_vertex3f(0,-0.340999,0.365677),_vertex3f(0,-0.334565,0.371572),_vertex3f(0,-0.32803,0.377355),_vertex3f(0,-0.321394,0.383022),_vertex3f(0,-0.31466,0.388573),_vertex3f(0,-0.307831,0.394005),_vertex3f(0,-0.300908,0.399318),_vertex3f(0,-0.293893,0.404509),_vertex3f(0,-0.286788,0.409576),_vertex3f(0,-0.279596,0.414519),_vertex3f(0,-0.27232,0.419335),_vertex3f(0,-0.26496,0.424024),_vertex3f(0,-0.257519,0.428584),_vertex3f(0,-0.25,0.433013),_vertex3f(0,-0.242405,0.43731),_vertex3f(0,-0.234736,0.441474),_vertex3f(0,-0.226995,0.445503),_vertex3f(0,-0.219186,0.449397),_vertex3f(0,-0.211309,0.453154),_vertex3f(0,-0.203368,0.456773),_vertex3f(0,-0.195366,0.460252),_vertex3f(0,-0.187303,0.463592),_vertex3f(0,-0.179184,0.46679),_vertex3f(0,-0.17101,0.469846),_vertex3f(0,-0.162784,0.472759),_vertex3f(0,-0.154509,0.475528),_vertex3f(0,-0.146186,0.478152),_vertex3f(0,-0.137819,0.480631),_vertex3f(0,-0.12941,0.482963),_vertex3f(0,-0.120961,0.485148),_vertex3f(0,-0.112476,0.487185),_vertex3f(0,-0.103956,0.489074),_vertex3f(0,-0.0954045,0.490814),_vertex3f(0,-0.0868241,0.492404),_vertex3f(0,-0.0782172,0.493844),_vertex3f(0,-0.0695866,0.495134),_vertex3f(0,-0.0609347,0.496273),_vertex3f(0,-0.0522642,0.497261),_vertex3f(0,-0.0435779,0.498097),_vertex3f(0,-0.0348782,0.498782),_vertex3f(0,-0.026168,0.499315),_vertex3f(0,-0.0174497,0.499695),_vertex3f(0,-0.0087262,0.499924),_vertex3f(0,0,0.5),_vertex3f(0,0.0087262,0.499924),_vertex3f(0,0.0174497,0.499695),_vertex3f(0,0.026168,0.499315),_vertex3f(0,0.0348782,0.498782),_vertex3f(0,0.0435779,0.498097),_vertex3f(0,0.0522642,0.497261),_vertex3f(0,0.0609347,0.496273),_vertex3f(0,0.0695866,0.495134),_vertex3f(0,0.0782172,0.493844),_vertex3f(0,0.0868241,0.492404),_vertex3f(0,0.0954045,0.490814),_vertex3f(0,0.103956,0.489074),_vertex3f(0,0.112476,0.487185),_vertex3f(0,0.120961,0.485148),_vertex3f(0,0.12941,0.482963),_vertex3f(0,0.137819,0.480631),_vertex3f(0,0.146186,0.478152),_vertex3f(0,0.154509,0.475528),_vertex3f(0,0.162784,0.472759),_vertex3f(0,0.17101,0.469846),_vertex3f(0,0.179184,0.46679),_vertex3f(0,0.187303,0.463592),_vertex3f(0,0.195366,0.460252),_vertex3f(0,0.203368,0.456773),_vertex3f(0,0.211309,0.453154),_vertex3f(0,0.219186,0.449397),_vertex3f(0,0.226995,0.445503),_vertex3f(0,0.234736,0.441474),_vertex3f(0,0.242405,0.43731),_vertex3f(0,0.25,0.433013),_vertex3f(0,0.257519,0.428584),_vertex3f(0,0.26496,0.424024),_vertex3f(0,0.27232,0.419335),_vertex3f(0,0.279596,0.414519),_vertex3f(0,0.286788,0.409576),_vertex3f(0,0.293893,0.404509),_vertex3f(0,0.300908,0.399318),_vertex3f(0,0.307831,0.394005),_vertex3f(0,0.31466,0.388573),_vertex3f(0,0.321394,0.383022),_vertex3f(0,0.32803,0.377355),_vertex3f(0,0.334565,0.371572),_vertex3f(0,0.340999,0.365677),_vertex3f(0,0.347329,0.35967),_vertex3f(0,0.353553,0.353553),_vertex3f(0,0.35967,0.347329),_vertex3f(0,0.365677,0.340999),_vertex3f(0,0.371572,0.334565),_vertex3f(0,0.377355,0.32803),_vertex3f(0,0.383022,0.321394),_vertex3f(0,0.388573,0.31466),_vertex3f(0,0.394005,0.307831),_vertex3f(0,0.399318,0.300908),_vertex3f(0,0.404509,0.293893),_vertex3f(0,0.409576,0.286788),_vertex3f(0,0.414519,0.279596),_vertex3f(0,0.419335,0.27232),_vertex3f(0,0.424024,0.26496),_vertex3f(0,0.428584,0.257519),_vertex3f(0,0.433013,0.25),_vertex3f(0,0.43731,0.242405),_vertex3f(0,0.441474,0.234736),_vertex3f(0,0.445503,0.226995),_vertex3f(0,0.449397,0.219186),_vertex3f(0,0.453154,0.211309),_vertex3f(0,0.456773,0.203368),_vertex3f(0,0.460252,0.195366),_vertex3f(0,0.463592,0.187303),_vertex3f(0,0.46679,0.179184),_vertex3f(0,0.469846,0.17101),_vertex3f(0,0.472759,0.162784),_vertex3f(0,0.475528,0.154509),_vertex3f(0,0.478152,0.146186),_vertex3f(0,0.480631,0.137819),_vertex3f(0,0.482963,0.12941),_vertex3f(0,0.485148,0.120961),_vertex3f(0,0.487185,0.112476),_vertex3f(0,0.489074,0.103956),_vertex3f(0,0.490814,0.0954045),_vertex3f(0,0.492404,0.0868241),_vertex3f(0,0.493844,0.0782172),_vertex3f(0,0.495134,0.0695866),_vertex3f(0,0.496273,0.0609347),_vertex3f(0,0.497261,0.0522642),_vertex3f(0,0.498097,0.0435779),_vertex3f(0,0.498782,0.0348782),_vertex3f(0,0.499315,0.026168),_vertex3f(0,0.499695,0.0174497),_vertex3f(0,0.499924,0.0087262),_vertex3f(0,0.5,0)},180};
	_revOBJ revFX;

	_rueda wheel;
	_eje eje;
	_rueda_eje rueda_eje;

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

	float last_x;	//CONTROL RELATIVE POSITION MOUASE
	float last_y;	
};

#endif
