#include "plyobj.h"
#include "file_ply_stl.h"

/*
numero de triangulos numero de puntos * n (numero de rotaciones) -1;
*/
void _plyObj::construct(const string name){
    vector<float> VerticesPly;
    vector<unsigned int> TrianglesPly;
    _file_ply plyfile;
    if(plyfile.open(name)){
        plyfile.read(VerticesPly,TrianglesPly);
        plyfile.close();
        for(int i = 0;i < static_cast<int>(VerticesPly.size());i=i+3){
            _vertex3f temp(VerticesPly.at(i),VerticesPly.at(i+1),VerticesPly.at(i+2));
            Vertices.push_back(temp);
        }
        for(int i = 0;i< static_cast<int>(TrianglesPly.size());i=i+3){
            _vertex3ui temp(TrianglesPly.at(i),TrianglesPly.at(i+1),TrianglesPly.at(i+2));
            Triangles.push_back(temp);
        }
    }
}

void _plyObj::File(const string name){
    construct(name);
}

_plyObj::_plyObj(const string name)
{
    construct(name);
}

_plyObj::_plyObj()
{
}
