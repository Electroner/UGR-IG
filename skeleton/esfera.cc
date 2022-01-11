#include "esfera.h"

_Esfera::_Esfera(){
        vector<_vertex3f> perfil;
    for(int i=100;i>=0;i--){
        float x=0;
        float y=cos(i*M_PI/100);
        float z=sin(i*M_PI/100);
        perfil.push_back(_vertex3f(x/2,y/2,z/2));
        //cout<< "_vertex3f("<<x/2<<","<<y/2<<","<<z/2<<"),";
    }
    this->ChangeREV(perfil,100);
}

_Esfera::_Esfera(int n){
    vector<_vertex3f> perfil;
    for(int i=100;i>=0;i--){
        float x=0;
        float y=cos(i*M_PI/100);
        float z=sin(i*M_PI/100);
        perfil.push_back(_vertex3f(x/2,y/2,z/2));
        //cout<< "_vertex3f("<<x/2<<","<<y/2<<","<<z/2<<"),";
    }
    this->ChangeREV(perfil,n);
}

_Esfera::_Esfera(int n,int k){
    vector<_vertex3f> perfil;
    for(int i=k;i>=0;i--){
        float x=0;
        float y=cos(i*M_PI/k);
        float z=sin(i*M_PI/k);
        perfil.push_back(_vertex3f(x/2,y/2,z/2));
        //cout<< "_vertex3f("<<x/2<<","<<y/2<<","<<z/2<<"),";
    }
    this->ChangeREV(perfil,n);
}