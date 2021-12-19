/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#include "object3d.h"
#include "file_ply_stl.h"
#include "materials.h"

using namespace _colors_ne;

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < static_cast<long>(Triangles.size()); i++)
	{
		glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
		glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
		glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
	}
	glEnd();
}

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < static_cast<long>(Triangles.size()); i++)
	{
		glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
		glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
		glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
	}
	glEnd();
}

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < static_cast<long>(Triangles.size()); i++)
	{
		if (i % 2 == 0)
		{
			glColor3fv((GLfloat *)&BLACK);
		}
		else
		{
			glColor3fv((GLfloat *)&WHITE);
		}
		glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
		glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
		glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
	}
	glEnd();
}

void _object3D::draw_lighted_flat_shading()
{
	if (!Triangles.empty())
	{
		compute_triangles_normals();

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);

		glBegin(GL_TRIANGLES);
		for (unsigned int i = 0; i < Triangles.size(); i++)
		{
			glNormal3f(Triangles_normals[i].x, Triangles_normals[i].y, Triangles_normals[i].z);
			glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
			glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
			glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
		}
		glEnd();

		glPolygonMode(GL_FRONT, GL_FILL);
		glShadeModel(GL_SMOOTH);

		GLfloat light_position[] = {0.1, 1.0, 1.0, 0.0};
		GLfloat light_ambient[] = {1.0, 1.0, 1.0};
		GLfloat light_diffuse[] = {0.7, 0.7, 0.7, 0.7};
    	GLfloat light_specular[] = {0.3, 0.3, 0.3, 0.3};

		glLightfv(GL_LIGHT0, GL_POSITION,(GLfloat*) &light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT,(GLfloat*) &light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE,(GLfloat*) &light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR,(GLfloat*) &light_specular);

		//MATERAIAL
		glMaterialfv(GL_FRONT, GL_AMBIENT,(GLfloat*) &NewMaterialsAmbient::CHROME);
		glMaterialfv(GL_FRONT, GL_DIFFUSE,(GLfloat*) &NewMaterialsDiffuse::CHROME);
		glMaterialfv(GL_FRONT, GL_SPECULAR,(GLfloat*) &NewMaterialsSpecular::CHROME);
		glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,(GLfloat *)&NewMaterialsShininess::CHROME);
		
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHTING);
	}
}

void _object3D::draw_lighted_smooth_shading(){	
	compute_vertices_normals();

	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light_ambient[] = {1.0, 1.0, 1.0};
    GLfloat light_position[] = {0.0, 0.0, 1.0, 0.0};
    GLfloat light_diffuse[] = {0.7, 0.7, 0.7, 0.7};
    GLfloat light_specular[] = {0.3, 0.3, 0.3, 0.3};
	GLfloat light_shininess[] = {50.0};

	glLightfv(GL_LIGHT0, GL_POSITION,(GLfloat*) &light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT,(GLfloat*) &light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,(GLfloat*) &light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR,(GLfloat*) &light_specular);

	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&NewMaterialsAmbient::GOLD);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&NewMaterialsDiffuse::GOLD);
  	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&NewMaterialsSpecular::GOLD);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,(GLfloat *)&NewMaterialsShininess::GOLD);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	for(unsigned int i =0; i < Triangles.size(); ++i){
		glNormal3fv((GLfloat*) &Vertices_normals[Triangles[i]._0]);
		glVertex3fv((GLfloat*) &Vertices[Triangles[i]._0]);
		glNormal3fv((GLfloat*) &Vertices_normals[Triangles[i]._1]);
		glVertex3fv((GLfloat*) &Vertices[Triangles[i]._1]);
		glNormal3fv((GLfloat*) &Vertices_normals[Triangles[i]._2]);
		glVertex3fv((GLfloat*) &Vertices[Triangles[i]._2]);
	}
	glEnd();

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_NORMALIZE);
}

void _object3D::draw_texture()
{
	if (!Triangles.empty()){
		compute_triangles_normals();
		compute_vertices_normals();

    	glEnable(GL_TEXTURE_2D);
    	glEnable(GL_TEXTURE_GEN_S);
    	glEnable(GL_TEXTURE_GEN_T);
    	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    	draw_lighted_flat_shading();
    	glDisable(GL_TEXTURE_GEN_S);
    	glDisable(GL_TEXTURE_GEN_T);
    	glDisable(GL_TEXTURE_2D);
	}
}
void _object3D::Translate(_vertex3f _vector)
{
	for (unsigned int i = 0; i < Vertices.size(); i++)
	{
		Vertices.at(i)._0 = Vertices.at(i)._0 + _vector._0;
		Vertices.at(i)._1 = Vertices.at(i)._1 + _vector._1;
		Vertices.at(i)._2 = Vertices.at(i)._2 + _vector._2;
	}
}

void _object3D::Rotate(float _angle)
{
	for (unsigned int i = 0; i < Vertices.size(); i++)
	{
		Vertices.at(i)._0 = Vertices.at(i)._0 * cos(_angle) + Vertices.at(i)._1 * sin(_angle);
		Vertices.at(i)._1 = -Vertices.at(i)._0 * sin(_angle) + Vertices.at(i)._1 * cos(_angle);
		Vertices.at(i)._2 = Vertices.at(i)._2;
	}
}

void _object3D::Resize(float _factor)
{
	for (unsigned int i = 0; i < Vertices.size(); i++)
	{
		Vertices.at(i)._0 = Vertices.at(i)._0 * _factor;
		Vertices.at(i)._1 = Vertices.at(i)._1 * _factor;
		Vertices.at(i)._2 = Vertices.at(i)._2 * _factor;
	}
}

void _object3D::compute_triangles_normals()
{
	Triangles_normals.resize(Triangles.size());

	// Calcular normales a las caras
	for (unsigned int i=0;i<Triangles.size();i++){
		_vertex3f a = Vertices[Triangles[i]._1] - Vertices[Triangles[i]._0];
		_vertex3f b = Vertices[Triangles[i]._2] - Vertices[Triangles[i]._0];
		_vertex3f normal = a.cross_product(b);

		Triangles_normals[i] = normal.normalize();
	}	
}

void _object3D::compute_vertices_normals()
{
	compute_triangles_normals();
	Vertices_normals.resize(Vertices.size());

	for (unsigned int i = 0; i < Triangles.size(); i++)
	{
		Vertices_normals[Triangles[i]._0] += Triangles_normals[i];
		Vertices_normals[Triangles[i]._1] += Triangles_normals[i];
		Vertices_normals[Triangles[i]._2] += Triangles_normals[i];
	}

	for (unsigned int i = 0; i < Vertices_normals.size(); i++)
	{
		Vertices_normals[i].normalize();
	}
}