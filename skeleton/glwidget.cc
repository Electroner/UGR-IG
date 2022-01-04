/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#include "glwidget.h"
#include "materials.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;

/*****************************************************************************/ /**
																				 *
																				 *
																				 *
																				 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1) : Window(Window1)
{
	setMinimumSize(300, 300);
	setFocusPolicy(Qt::StrongFocus);
}

/*****************************************************************************/ /**
																				 * Evento tecla pulsada
																				 *
																				 *
																				 *
																				 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
	switch (Keyevent->key())
	{
	case Qt::Key_1:
		Object = OBJECT_TETRAHEDRON;
		break;
	case Qt::Key_2:
		Object = OBJECT_CUBE;
		break;
	case Qt::Key_3:
		plyobj.File((QFileDialog::getOpenFileName(this, tr("Open PLY"), "~", tr("PLY Files (*.ply)"))).toStdString());
		Object = OBJECT_PLY;
		break;
	case Qt::Key_4:
		Object = OBJECT_REV;
		break;
	case Qt::Key_5:
		Object = OBJECT_CILINDRO;
		break;
	case Qt::Key_6:
		Object = OBJECT_SPHERE;
		break;
	case Qt::Key_7:
		Object = OBJECT_REVFX;
		break;
	case Qt::Key_8:
		Object = OBJECT_WHEEL;
		break;
	case Qt::Key_9:
		Object = OBJECT_EJE;
		break;
	case Qt::Key_0:
		Object = OBJECT_RUEDA_EJE;
		break;
	case Qt::Key_Apostrophe:
		Object = OBJECT_CHESS_BOARD;
		break;

	case Qt::Key_F1:
		Draw_point = !Draw_point;
		break;
	case Qt::Key_F2:
		Draw_line = !Draw_line;
		break;
	case Qt::Key_F3:
		Draw_fill = !Draw_fill;
		break;
	case Qt::Key_F4:
		Draw_chess = !Draw_chess;
		break;
	case Qt::Key_F5:
		Draw_flat_shading = !Draw_flat_shading;
		break;
	case Qt::Key_F6:
		Draw_smooth_shading = !Draw_smooth_shading;
		break;
	case Qt::Key_F7:
		Draw_texture = !Draw_texture;
		break;

	case Qt::Key_Left:
		Observer_angle_y -= ANGLE_STEP;
		break;
	case Qt::Key_Right:
		Observer_angle_y += ANGLE_STEP;
		break;
	case Qt::Key_Up:
		Observer_angle_x -= ANGLE_STEP;
		break;
	case Qt::Key_Down:
		Observer_angle_x += ANGLE_STEP;
		break;
	case Qt::Key_PageUp:
		Observer_distance *= 1.2;
		break;
	case Qt::Key_PageDown:
		Observer_distance /= 1.2;
		break;

	case Qt::Key_A:
		animation = !animation;
		set_animation();
		break;

	case Qt::Key_J:
		light0_enabled = !light0_enabled;
		break;
	case Qt::Key_K:
		light1_enabled = !light1_enabled;
		break;

	case Qt::Key_P:
		perspective = !perspective;
		break;

	case Qt::Key_Y:
		Draw_axis != Draw_axis;
		break;

	case Qt::Key_Z:
		Object = OBJECT_COMPASS;
		break;
	case Qt::Key_X:
		Object = OBJECT_ARM;
		break;
	case Qt::Key_C:
		Object = OBJECT_END;
		break;
	case Qt::Key_V:
		Object = OBJECT_TIP;
		break;
	case Qt::Key_B:
		Object = OBJECT_BASE;
		break;

	case Qt::Key_Escape:
		exit(0);
		break;

	case Qt::Key_M:
		QStringList items;
		items << tr("PEARL") << tr("BRASS") << tr("RUBY") << tr("LIME");
		bool ok;
		string itemLabel;
		QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"), tr("Material:"), items, 0, false, &ok);
		if (ok && !item.isEmpty())
		{
			itemLabel = item.toStdString();
		}
		material = itemLabel;
		break;

	}
	update();
}

void _gl_widget::mouseMoveEvent(QMouseEvent *Event)
{
	int x = Event->x(), y = Event->y();

	if (Event->buttons() & Qt::LeftButton)
	{
		if (last_x < x)
		{
			Observer_angle_y += ANGLE_STEP;
		}
		else if (last_x > x)
		{
			Observer_angle_y -= ANGLE_STEP;
		}

		if (last_y < y)
		{
			Observer_angle_x += ANGLE_STEP;
		}
		else if (last_y > y)
		{
			Observer_angle_x -= ANGLE_STEP;
		}
		last_x = x;
		last_y = y;
	}
	update();
}

void _gl_widget::wheelEvent(QWheelEvent *Event)
{
	const int degrees = Event->delta() / 8; // WHY: https://stackoverflow.com/questions/7753123/why-is-wheeldelta-120

	if (perspective)
	{
		if (degrees > 0)
		{
			if (Observer_distance > 0)
			{
				Observer_distance -= 0.2;
			}
		}
		else if (degrees < 0)
		{
			Observer_distance += 0.2;
		}
	}
	else
	{
		if (degrees > 0)
		{
			if (reduction > 0.01)
			{
				reduction -= 0.01;
			}
		}
		else if (degrees < 0.01)
		{
			reduction += 0.01;
		}
	}
	Event->accept();
	update();
}

/*****************************************************************************/ /**
																				 * Limpiar ventana
																				 *
																				 *
																				 *
																				 *****************************************************************************/

void _gl_widget::clear_window()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/*****************************************************************************/ /**
																				 * Funcion para definir la transformación de proyeccion
																				 *
																				 *
																				 *
																				 *****************************************************************************/

void _gl_widget::change_projection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
	// Front_plane>0  Back_plane>PlanoDelantero)
	if (perspective)
	{
		glFrustum(X_MIN, X_MAX, Y_MIN, Y_MAX, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
	}
	else
	{

		glOrtho(X_MIN / reduction, X_MAX / reduction, Y_MIN / reduction, Y_MAX / reduction, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
	}
}

/*****************************************************************************/ /**
																				 * Funcion para definir la transformación de vista (posicionar la camara)
																				 *
																				 *
																				 *
																				 *****************************************************************************/

void _gl_widget::change_observer()
{
	// posicion del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -Observer_distance);
	glRotatef(Observer_angle_x, 1, 0, 0);
	glRotatef(Observer_angle_y, 0, 1, 0);
}

/*****************************************************************************/ /**
																				 * Funcion que dibuja los objetos
																				 *
																				 *
																				 *
																				 *****************************************************************************/

void _gl_widget::draw_objects()
{
	if (Draw_axis)
	{
		Axis.draw_line();
	}

	if (Draw_point)
	{
		glPointSize(5);
		glColor3fv((GLfloat *)&BLACK);
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_point();
			break;

		case OBJECT_CUBE:
			Cube.draw_point();
			break;

		case OBJECT_PLY:
			plyobj.draw_point();
			break;

		case OBJECT_REV:
			revOBJ.draw_point();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_point();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_point();
			break;

		case OBJECT_REVFX:
			revFX.draw_point();
			break;

		case OBJECT_WHEEL:
			wheel.draw_point();
			break;

		case OBJECT_EJE:
			eje.draw_point();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_point();
			break;

		case OBJECT_COMPASS:
			Compass.draw_point();
			break;
		case OBJECT_ARM:
			Arm.draw_point();
			break;
		case OBJECT_END:
			End.draw_point();
			break;
		case OBJECT_TIP:
			Tip.draw_point();
			break;
		case OBJECT_BASE:
			Base.draw_point();
			break;

		default:
			break;
		}
	}

	if (Draw_line)
	{
		glLineWidth(3);
		glColor3fv((GLfloat *)&BLACK);
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_line();
			break;

		case OBJECT_CUBE:
			Cube.draw_line();
			break;

		case OBJECT_PLY:
			plyobj.draw_line();
			break;

		case OBJECT_REV:
			revOBJ.draw_line();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_line();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_line();
			break;

		case OBJECT_REVFX:
			revFX.draw_line();
			break;

		case OBJECT_WHEEL:
			wheel.draw_line();
			break;

		case OBJECT_EJE:
			eje.draw_line();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_line();
			break;

		case OBJECT_COMPASS:
			Compass.draw_line();
			break;
		case OBJECT_ARM:
			Arm.draw_line();
			break;
		case OBJECT_END:
			End.draw_line();
			break;
		case OBJECT_TIP:
			Tip.draw_line();
			break;
		case OBJECT_BASE:
			Base.draw_line();
			break;

		default:
			break;
		}
	}

	if (Draw_fill)
	{
		glColor3fv((GLfloat *)&BLUE);
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_fill();
			break;

		case OBJECT_CUBE:
			Cube.draw_fill();
			break;

		case OBJECT_PLY:
			plyobj.draw_fill();
			break;

		case OBJECT_REV:
			revOBJ.draw_fill();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_fill();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_fill();
			break;

		case OBJECT_REVFX:
			revFX.draw_fill();
			break;

		case OBJECT_WHEEL:
			wheel.draw_fill();
			break;

		case OBJECT_EJE:
			eje.draw_fill();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_fill();
			break;

		case OBJECT_COMPASS:
			Compass.draw_fill();
			break;
		case OBJECT_ARM:
			Arm.draw_fill();
			break;
		case OBJECT_END:
			End.draw_fill();
			break;
		case OBJECT_TIP:
			Tip.draw_fill();
			break;
		case OBJECT_BASE:
			Base.draw_fill();
			break;

		default:
			break;
		}
	}

	if (Draw_chess)
	{
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_chess();
			break;

		case OBJECT_CUBE:
			Cube.draw_chess();
			break;
		case OBJECT_PLY:
			plyobj.draw_chess();
			break;

		case OBJECT_REV:
			revOBJ.draw_chess();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_chess();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_chess();
			break;

		case OBJECT_REVFX:
			revFX.draw_chess();
			break;

		case OBJECT_WHEEL:
			wheel.draw_chess();
			break;

		case OBJECT_EJE:
			eje.draw_chess();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_chess();
			break;

		case OBJECT_COMPASS:
			Compass.draw_chess();
			break;
		case OBJECT_ARM:
			Arm.draw_chess();
			break;
		case OBJECT_END:
			End.draw_chess();
			break;
		case OBJECT_TIP:
			Tip.draw_chess();
			break;
		case OBJECT_BASE:
			Base.draw_chess();
			break;

		default:
			break;
		}
	}

	if (Draw_flat_shading)
	{
		build_lights();
		build_material(material);
		glEnable(GL_LIGHTING);
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_lighted_flat_shading();
			break;

		case OBJECT_CUBE:
			Cube.draw_lighted_flat_shading();
			break;

		case OBJECT_PLY:
			plyobj.draw_lighted_flat_shading();
			break;

		case OBJECT_REV:
			revOBJ.draw_lighted_flat_shading();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_lighted_flat_shading();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_lighted_flat_shading();
			break;

		case OBJECT_REVFX:
			revFX.draw_lighted_flat_shading();
			break;

		case OBJECT_WHEEL:
			wheel.draw_lighted_flat_shading();
			break;

		case OBJECT_EJE:
			eje.draw_lighted_flat_shading();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_lighted_flat_shading();
			break;

		case OBJECT_COMPASS:
			Compass.draw_lighted_flat_shading();
			break;
		case OBJECT_ARM:
			Arm.draw_lighted_flat_shading();
			break;
		case OBJECT_END:
			End.draw_lighted_flat_shading();
			break;
		case OBJECT_TIP:
			Tip.draw_lighted_flat_shading();
			break;
		case OBJECT_BASE:
			Base.draw_lighted_flat_shading();
			break;

		default:
			break;
		}
		glDisable(GL_LIGHTING);
	}

	if (Draw_smooth_shading)
	{
		build_lights();
		build_material(material);
		glEnable(GL_LIGHTING);
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_lighted_smooth_shading();
			break;

		case OBJECT_CUBE:
			Cube.draw_lighted_smooth_shading();
			break;

		case OBJECT_PLY:
			plyobj.draw_lighted_smooth_shading();
			break;

		case OBJECT_REV:
			revOBJ.draw_lighted_smooth_shading();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_lighted_smooth_shading();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_lighted_smooth_shading();
			break;

		case OBJECT_REVFX:
			revFX.draw_lighted_smooth_shading();
			break;

		case OBJECT_WHEEL:
			wheel.draw_lighted_smooth_shading();
			break;

		case OBJECT_EJE:
			eje.draw_lighted_smooth_shading();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_lighted_smooth_shading();
			break;
		
		case OBJECT_COMPASS:
			Compass.draw_lighted_smooth_shading();
			break;
		case OBJECT_ARM:
			Arm.draw_lighted_smooth_shading();
			break;
		case OBJECT_END:
			End.draw_lighted_smooth_shading();
			break;
		case OBJECT_TIP:
			Tip.draw_lighted_smooth_shading();
			break;
		case OBJECT_BASE:
			Base.draw_lighted_smooth_shading();
			break;

		default:
			break;
		}
		glDisable(GL_LIGHTING);
	}

	if (Draw_texture)
	{
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_texture();
			break;

		case OBJECT_CUBE:
			Cube.draw_texture();
			break;

		case OBJECT_PLY:
			plyobj.draw_texture();
			break;

		case OBJECT_REV:
			revOBJ.draw_texture();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_texture();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_texture();
			break;

		case OBJECT_REVFX:
			revFX.draw_texture();
			break;

		case OBJECT_WHEEL:
			wheel.draw_texture();
			break;

		case OBJECT_EJE:
			eje.draw_texture();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_texture();
			break;

		case OBJECT_CHESS_BOARD:
			chess_board.draw_texture();
			break;

		case OBJECT_COMPASS:
			Compass.draw_texture();
			break;
		case OBJECT_ARM:
			Arm.draw_texture();
			break;
		case OBJECT_END:
			End.draw_texture();
			break;
		case OBJECT_TIP:
			Tip.draw_texture();
			break;
		case OBJECT_BASE:
			Base.draw_texture();
			break;

		default:
			break;
		}
	}
}

/*****************************************************************************/ /**
																				 * Evento de dibujado
																				 *
																				 *
																				 *
																				 *****************************************************************************/

void _gl_widget::paintGL()
{
	clear_window();
	change_projection();
	change_observer();
	draw_objects();
}

/*****************************************************************************/ /**
																				 * Evento de cambio de tamaño de la ventana
																				 *
																				 *
																				 *
																				 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
	glViewport(0, 0, Width1, Height1);
}

void _gl_widget::build_lights()
{
	if (light0_enabled)
	{

		glEnable(GL_LIGHT0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		// glLoadIdentity();
		GLfloat light_ambient[] = {1.0, 1.0, 1.0};
		GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
		GLfloat light_diffuse[] = {0.7, 0.7, 0.7, 0.7};
		GLfloat light_specular[] = {0.3, 0.3, 0.3, 0.3};
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		glPopMatrix();
	}
	else
	{
		glDisable(GL_LIGHT0);
	}
	if (light1_enabled)
	{

		glEnable(GL_LIGHT1);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		// glLoadIdentity();
		GLfloat light_ambient1[] = {1.0, 1.0, 1.0};
		GLfloat light_position1[] = {-1.0, -1.0, -1.0, 0.0};
		GLfloat light_diffuse1[] = {0.0, 0.8, 0.3, 0.2};
		GLfloat light_specular1[] = {0.1, 0.0, 0.3, 1.0};
		glPushMatrix();
		glRotatef(angle_ligth, 0, 1, 0);
		glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
		glPopMatrix();
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
		glPopMatrix();
	}
	else
	{
		glDisable(GL_LIGHT1);
	}
}

void _gl_widget::build_material(string _material)
{
	if (_material == "PEARL")
	{
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *)&NewMaterialsAmbient::PEARL);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *)&NewMaterialsDiffuse::PEARL);
		glMaterialfv(GL_FRONT, GL_SPECULAR,
					 (GLfloat *)&NewMaterialsSpecular::PEARL);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,
					 (GLfloat *)&NewMaterialsShininess::PEARL);
		glPopMatrix();
	}
	if (_material == "BRASS")
	{
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *)&NewMaterialsAmbient::BRASS);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *)&NewMaterialsDiffuse::BRASS);
		glMaterialfv(GL_FRONT, GL_SPECULAR,
					 (GLfloat *)&NewMaterialsSpecular::BRASS);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,
					 (GLfloat *)&NewMaterialsShininess::BRASS);
		glPopMatrix();
	}
	if (_material == "RUBY")
	{
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *)&NewMaterialsAmbient::RUBY);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *)&NewMaterialsDiffuse::RUBY);
		glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *)&NewMaterialsSpecular::RUBY);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,
					 (GLfloat *)&NewMaterialsShininess::RUBY);
		glPopMatrix();
	}
	if (_material == "LIME")
	{
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *)&NewMaterialsAmbient::LIME);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *)&NewMaterialsDiffuse::LIME);
		glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *)&NewMaterialsSpecular::LIME);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,
					 (GLfloat *)&NewMaterialsShininess::LIME);
		glPopMatrix();
	}
}

void _gl_widget::set_animation()
{
	if (animation)
	{
		Timer->start(10);
	}
	else
	{
		Timer->stop();
	}
}

// FUNCION ASOCIADA AL TIMER PARA LA ANIMACION
void _gl_widget::tick()
{
	if (light1_enabled)
	{
		angle_ligth = (angle_ligth < 360) ? angle_ligth += 5 : angle_ligth = 0;
	}
	Compass.update();
	Arm.update();
	End.update();
	Tip.update();
	Base.update();
	update();
}

void _gl_widget::initializeGL()
{
	const GLubyte *strm;

	strm = glGetString(GL_VENDOR);
	std::cerr << "Vendor: " << strm << "\n";
	strm = glGetString(GL_RENDERER);
	std::cerr << "Renderer: " << strm << "\n";
	strm = glGetString(GL_VERSION);
	std::cerr << "OpenGL Version: " << strm << "\n";

	if (strm[0] == '1')
	{
		std::cerr << "Only OpenGL 1.X supported!\n";
		exit(-1);
	}

	strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
	std::cerr << "GLSL Version: " << strm << "\n";

	int Max_texture_size = 0;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
	std::cerr << "Max texture size: " << Max_texture_size << "\n";

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);

	Observer_angle_x = 0;
	Observer_angle_y = 0;
	Observer_distance = DEFAULT_DISTANCE;

	Draw_point = false;
	Draw_line = false;
	Draw_fill = false;
	Draw_chess = false;
	Draw_flat_shading = false;
	Draw_smooth_shading = true;
	Draw_texture = false;
	Draw_axis = true;

	animation = false;
	Timer = new QTimer(this);
	connect(Timer, SIGNAL(timeout()), this, SLOT(tick()));

	angle_ligth = 0;

	light0_enabled = true;
	light1_enabled = true;

	revFX.function_revobj(&RevFuncitonFX, -1, 1, 0.01, 180, true, true);

	perspective = true;

	last_x = 0;
	last_y = 0;

	Object = OBJECT_COMPASS;

	QString File_name("./textures/earth.jpg");
	QImageReader Reader(File_name);
	Reader.setAutoTransform(true);
	Image = Reader.read();
	if (Image.isNull())
	{
		QMessageBox::information(
			this, QGuiApplication::applicationDisplayName(),
			tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
		exit(-1);
	}
	Image = Image.mirrored();
	Image = Image.convertToFormat(QImage::Format_RGB888);

	// Code to control the application of the texture
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Code to pass the image to OpenGL to form a texture 2D
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Image.width(), Image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, Image.bits());
}
