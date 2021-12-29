#include "cilindro.h"

_Cilindro::_Cilindro(){
    this->ChangeREV(vector<_vertex3f>{_vertex3f(0,-0.5,0),_vertex3f(0.5,-0.5,0),_vertex3f(0.5,0.5,0),_vertex3f(0,0.5,0)},360);
}

_Cilindro::_Cilindro(int n){
    this->ChangeREV(vector<_vertex3f>{_vertex3f(0,-0.5,0),_vertex3f(0.5,-0.5,0),_vertex3f(0.5,0.5,0),_vertex3f(0,0.5,0)},n);
}
