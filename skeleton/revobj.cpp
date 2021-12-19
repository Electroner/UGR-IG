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
	}
}

_revOBJ::~_revOBJ()
{
	Triangles.~vector();
	Vertices.~vector();
	pLine.~vector();
}

void _revOBJ::ChangeN(int _n)
{
	if (checkN(_n))
	{
		this->n = _n;
		this->Construct();
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
	}
}

void _revOBJ::ChangeOBJ(vector<_vertex3f> _pLine, int _n,AxisRotation _axis)
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
	}
}

void _revOBJ::Construct()
{
	bool Tsup = false;
	int suppos = 0;
	bool Tinf = false;
	int infpos = 0;
	int verticeseje = 0;
	_vertex3f inferior = (1000000.0);
	_vertex3f superior = (-1000000.0);

	vector<_vertex3f> lateral;		   //Polilina solo del Lateral
	vector<_vertex3f> localVertices;   //vertices en la seccion lateral
	vector<_vertex3ui> localTriangles; //triangulos en la seccion lateral

	/*POTIN*/

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
				//Y
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

	//Reservamos para los triangulos laterales y los calculamos
	localTriangles.reserve((lateral.size() * getN() * 2));

	//Reserva del Vector Triangulos
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

			//cout<<"("<<temp._0<<","<<temp._1<<","<<temp._2<<") \t| i:"<<i<<" , j:"<<j<<endl;

			temp._0 = (j + 1 + ((i * lateral.size()) % localVertices.size()));
			temp._1 = (j + ((lateral.size() * (i + 1)) % localVertices.size()));
			temp._2 = ((j + 1 + ((lateral.size() * (i + 1)) % localVertices.size())) % localVertices.size());
			Triangles.emplace_back(temp);

			//cout<<"("<<temp._0<<","<<temp._1<<","<<temp._2<<") \t| i:"<<i<<" , j:"<<j<<endl;
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