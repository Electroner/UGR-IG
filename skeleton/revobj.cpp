
#include "revobj.h"

bool _revOBJ::checkN(const int n)
{
	if (n < 3)
	{
		return false;
	}
	return true;
}

_revOBJ::_revOBJ(int _n)
{
	if (checkN(_n))
	{
		this->n = _n;
		vector<_vertex3f> temp = {_vertex3f(1, 1, 0)};
		pLine.reserve(temp.size());
		for (int i = 0; i < static_cast<int>(temp.size()); i++)
		{
			this->pLine.emplace_back(temp.at(i));
		}
		this->Construct();
		texture_coordinates.clear();
	}
}

_revOBJ::_revOBJ(vector<_vertex3f> _pLine, int _n)
{
	if (checkN(_n))
	{
		this->n = _n;
		pLine.reserve(_pLine.size());
		for (int i = 0; i < static_cast<int>(_pLine.size()); i++)
		{
			this->pLine.emplace_back(_pLine.at(i));
		}
		this->Construct();
		texture_coordinates.clear();
	}
}

_revOBJ::~_revOBJ()
{
	Triangles.~vector();
	Vertices.~vector();
	pLine.~vector();
	texture_coordinates.~vector();
}

void _revOBJ::ChangeN(int _n)
{
	if (checkN(_n))
	{
		this->n = _n;
		this->Construct();
		texture_coordinates.clear();
	}
}

void _revOBJ::SelectRotationAxis(AxisRotation _axis)
{
	this->axis_selection = _axis;
}

void _revOBJ::ChangeProfile(vector<_vertex3f> _pLine)
{
	this->pLine.clear();
	this->pLine.reserve(_pLine.size());
	for (int i = 0; i < static_cast<int>(_pLine.size()); i++)
	{
		this->pLine.emplace_back(_pLine.at(i));
	}
	this->Construct();
	texture_coordinates.clear();
}

void _revOBJ::ChangeREV(vector<_vertex3f> _pLine, int _n)
{
	if (checkN(_n))
	{
		this->n = _n;
		this->pLine.clear();
		this->pLine.reserve(_pLine.size());
		for (int i = 0; i < static_cast<int>(_pLine.size()); i++)
		{
			this->pLine.emplace_back(_pLine.at(i));
		}
		this->Construct();
		texture_coordinates.clear();
	}
}

void _revOBJ::ChangeOBJ(vector<_vertex3f> _pLine, int _n, AxisRotation _axis)
{
	if (checkN(_n))
	{
		this->n = _n;
		this->axis_selection = _axis;
		this->pLine.clear();
		this->pLine.reserve(_pLine.size());
		for (int i = 0; i < static_cast<int>(_pLine.size()); i++)
		{
			this->pLine.emplace_back(_pLine.at(i));
		}
		this->Construct();
		texture_coordinates.clear();
	}
}

void _revOBJ::function_revobj(float (*_fx)(float _x),float _min,float _max,float _precision,unsigned int _n,bool _topclosed,bool _bottomclosed){
	vector<_vertex3f> LocalpLine;
	_vertex3f point;
	float min = _min;
	if(_bottomclosed){
		point = _vertex3f(0,min,0);
		LocalpLine.push_back(point);
	}
	while(min < _max){
		point.x = 0;
		point.y = min;
		point.z = _fx(min);
		LocalpLine.push_back(point);
		min += _precision;
	}
	if(_topclosed){
		point = _vertex3f(0,_max,0);
		LocalpLine.push_back(point);
	}
	ChangeOBJ(LocalpLine,_n,AxisRotation::axis_y);
}

void _revOBJ::Construct()
{
	int suppos = 0;
	int infpos = 0;
	_vertex3f inferior = (1000000.0);
	_vertex3f superior = (-1000000.0);

	vector<_vertex3f> localVertices;   // vertices en la seccion lateral
	vector<_vertex3ui> localTriangles; // triangulos en la seccion lateral

	/* DETECCION DE TAPAS */

	for (int i = 0; i < static_cast<int>(pLine.size()); i++)
	{
		if (pLine.at(i)._0 == 0 && pLine.at(i)._1 < inferior._1 && pLine.at(i)._2 == 0)
		{
			inferior = pLine.at(i);
			infpos = i;
			Tinf = true;
			verticeseje++;
		}
		if (pLine.at(i)._0 == 0 && pLine.at(i)._1 > superior._1 && pLine.at(i)._2 == 0)
		{
			superior = pLine.at(i);
			suppos = i;
			Tsup = true;
			verticeseje++;
		}
	}

	lateral.reserve((pLine.size() - verticeseje));
	for (int i = 0; i < static_cast<int>(pLine.size()); i++)
	{
		if (!((Tinf == true && infpos == i) || (Tsup == true && suppos == i)))
		{
			lateral.emplace_back(pLine.at(i));
		}
	}

	/* VERTICES */

	localVertices.reserve(lateral.size() * getN());
	for (int i = 0; i < this->getN(); i++)
	{
		for (int k = 0; k < static_cast<int>(lateral.size()); k++)
		{
			float x = lateral.at(k)._0;
			float y = lateral.at(k)._1;
			float z = lateral.at(k)._2;

			float _x;
			float _y;
			float _z;

			switch (axis_selection)
			{
			case AxisRotation::axis_x:
				_x = x;
				_y = y * cos((2 * M_PI / n) * i) - z * sin((2 * M_PI / n) * i);
				_z = y * sin((2 * M_PI / n) * i) + z * cos((2 * M_PI / n) * i);
				localVertices.emplace_back(_vertex3f(_x, _y, _z));
				break;

			case AxisRotation::axis_y:
				_x = x * cos((2 * M_PI / n) * i) + z * sin((2 * M_PI / n) * i);
				_y = y;
				_z = -x * sin((2 * M_PI / n) * i) + z * cos((2 * M_PI / n) * i);
				localVertices.emplace_back(_vertex3f(_x, _y, _z));
				break;

			case AxisRotation::axis_z:
				_x = x * cos((2 * M_PI / n) * i) - y * sin((2 * M_PI / n) * i);
				_y = x * sin((2 * M_PI / n) * i) + y * cos((2 * M_PI / n) * i);
				_z = z;
				localVertices.emplace_back(_vertex3f(_x, _y, _z));
				break;

			default:
				// Y
				float _x = x * cos((2 * M_PI / n) * i) + z * sin((2 * M_PI / n) * i);
				float _y = y;
				float _z = -x * sin((2 * M_PI / n) * i) + z * cos((2 * M_PI / n) * i);
				localVertices.emplace_back(_vertex3f(_x, _y, _z));
				break;
			}
		}
	}

	Vertices.reserve((localVertices.size() + verticeseje));
	for (int i = 0; i < static_cast<int>(localVertices.size()); i++)
	{
		Vertices.emplace_back(localVertices.at(i));
	}
	if (Tinf)
	{
		Vertices.emplace_back(inferior);
	}
	if (Tsup)
	{
		Vertices.emplace_back(superior);
	}

	/* TRIANGULOS */

	// Reservamos para los triangulos laterales y los calculamos
	localTriangles.reserve((lateral.size() * getN() * 2));

	// Reserva del Vector Triangulos
	if (Tinf && Tsup)
	{
		Triangles.reserve(localTriangles.size() + (getN() * 2));
	}
	else if (Tinf || Tsup)
	{
		Triangles.reserve(localTriangles.size() + getN());
	}
	else
	{
		Triangles.reserve(localTriangles.size());
	}

	_vertex3ui temp;
	for (int i = 0; i < getN(); i++)
	{
		for (int j = 0; j < static_cast<int>(lateral.size() - 1); j++)
		{
			temp._2 = (j + ((i * lateral.size()) % localVertices.size()));
			temp._1 = (j + 1 + ((i * lateral.size()) % localVertices.size()));
			temp._0 = ((j + lateral.size() + ((i * lateral.size()) % localVertices.size())) % localVertices.size());
			Triangles.emplace_back(temp);

			// cout<<"("<<temp._0<<","<<temp._1<<","<<temp._2<<") \t| i:"<<i<<" , j:"<<j<<endl;

			temp._0 = (j + 1 + ((i * lateral.size()) % localVertices.size()));
			temp._1 = (j + ((lateral.size() * (i + 1)) % localVertices.size()));
			temp._2 = ((j + 1 + ((lateral.size() * (i + 1)) % localVertices.size())) % localVertices.size());
			Triangles.emplace_back(temp);

			// cout<<"("<<temp._0<<","<<temp._1<<","<<temp._2<<") \t| i:"<<i<<" , j:"<<j<<endl;
		}
	}

	if (Tinf)
	{
		for (int i = 0; i < getN(); i++)
		{
			temp._2 = ((lateral.size() * i) % localVertices.size());
			temp._1 = ((lateral.size() * (i + 1)) % localVertices.size());
			temp._0 = (Vertices.size() - 2);
			Triangles.emplace_back(temp);
		}
	}
	if (Tsup)
	{
		for (int i = 0; i < getN(); i++)
		{
			temp._0 = (((lateral.size() - 1) + (lateral.size() * i)));
			temp._1 = ((((lateral.size() - 1) + (lateral.size() * (i + 1))) % localVertices.size()));
			temp._2 = (Vertices.size() - 1);
			Triangles.emplace_back(temp);
		}
	}
}

_vertex2f _revOBJ::get_coordinates_vertex(int vertex){
	float vertical_division = (1.0 / (pLine.size() - 1));
	float horizontal_division = (1.0 / getN());
	int modulo_lateral = pLine.size() - 2;
	_vertex2f coord;
	coord._0 = (horizontal_division * (vertex / modulo_lateral));
	coord._1 = (vertical_division * (vertex % modulo_lateral)) + vertical_division;
	return coord;
}

void _revOBJ::constuct_texture_coordinates()
{
	revobj_texture_coordinates.reserve(Triangles.size() * 6);
	_vertex2f coord;
	int modulo_lateral = pLine.size() - 2;

	if (modulo_lateral > 1)
	{
		int vert1;
		int vert2;
		int vert3;
		for (int i = 0; i < getN(); i++)
		{
			for (int j = 0; j < static_cast<int>(lateral.size() - 1); j++)
			{
				//Vertice 1
				vert1 = ((j + lateral.size() + ((i * lateral.size()) % (lateral.size() * getN()))) % (lateral.size() * getN()));
				revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert1));
				//Vertice 2
				vert2 = (j + 1 + ((i * lateral.size()) % (lateral.size() * getN())));
				revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert2));
				//Vertice 3
				vert3 = (j + ((i * lateral.size()) % (lateral.size() * getN())));
				revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert3));

				cout << "(" << vert1 << "," << vert2 << "," << vert3 << ") \t| i:" << i << " , j:" << j << endl;
				cout << "(" << get_coordinates_vertex(vert1)._0 << "," << get_coordinates_vertex(vert1)._1 << ")" << endl;
				cout << "(" << get_coordinates_vertex(vert2)._0 << "," << get_coordinates_vertex(vert2)._1 << ")" << endl;
				cout << "(" << get_coordinates_vertex(vert3)._0 << "," << get_coordinates_vertex(vert3)._1 << ")" << endl;

				//vertice 1
				vert1 = (j + 1 + ((i * lateral.size()) % (lateral.size() * getN())));
				revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert1));
				//vertice 2
				vert2 = (j + ((lateral.size() * (i + 1)) % (lateral.size() * getN())));
				revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert2));
				//vertice 3
				vert3 = ((j + 1 + ((lateral.size() * (i + 1)) % (lateral.size() * getN()))) % (lateral.size() * getN()));
				revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert3));

				cout << "(" << vert1 << "," << vert2 << "," << vert3 << ") \t| i:" << i << " , j:" << j << endl;
				cout << "(" << get_coordinates_vertex(vert1)._0 << "," << get_coordinates_vertex(vert1)._1 << ")" << endl;
				cout << "(" << get_coordinates_vertex(vert2)._0 << "," << get_coordinates_vertex(vert2)._1 << ")" << endl;
				cout << "(" << get_coordinates_vertex(vert3)._0 << "," << get_coordinates_vertex(vert3)._1 << ")" << endl;
			}
		}
	}
	if (Tsup)
	{
		int vert1;
		int vert2;
		for (int i = 0; i < getN(); i++)
		{
			// Vertice inferior
			coord._0 = 0.5;
			coord._1 = 0.0;
			revobj_texture_coordinates.emplace_back(coord);
			//  Vertice 1
			vert1 = ((lateral.size() * (i + 1)) % (lateral.size() * getN()));
			revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert1));
			//  Vertice 2
			vert2 = ((lateral.size() * i) % (lateral.size() * getN()));
			revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert2));
		}
	}
	if (Tinf)
	{
		int vert1;
		int vert2;
		for (int i = 0; i < getN(); i++)
		{
			// Vertice 1
			vert1 = (((lateral.size() - 1) + (lateral.size() * i)));
			revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert1));
			//  Vertice 2
			vert2 = ((((lateral.size() - 1) + (lateral.size() * (i + 1))) % (lateral.size() * getN())));
			revobj_texture_coordinates.emplace_back(get_coordinates_vertex(vert2));
			//  Vertice superior
			coord._0 = 0.5;
			coord._1 = 1;
			revobj_texture_coordinates.push_back(coord);
		}
	}
}

void _revOBJ::draw_texture()
{
	if (revobj_texture_coordinates.size() == 0)
	{
		constuct_texture_coordinates();
	}
	if (revobj_texture_coordinates.size() > 0)
	{
		glEnable(GL_TEXTURE_2D);
		int j = 0;
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_TRIANGLES);
		for (unsigned int i = 0; i < Triangles.size(); i++)
		{
			j = 3 * i;
			glTexCoord2f(revobj_texture_coordinates.at(j)._0, revobj_texture_coordinates.at(j)._1);
			glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
			glTexCoord2f(revobj_texture_coordinates.at(j + 1)._0, revobj_texture_coordinates.at(j + 1)._1);
			glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
			glTexCoord2f(revobj_texture_coordinates.at(j + 2)._0, revobj_texture_coordinates.at(j + 2)._1);
			glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}