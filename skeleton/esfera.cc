#include "esfera.h"

inline float _Esfera::round(float x, int d){
    return ((floor(((x)*pow(10,d))+.5))/pow(10,d));
}

_Esfera::_Esfera(){
    vector<_vertex3f> perfil;
    for(int i = 100; i >= 0; i--){
        float x=0;
        float y=round(cos((i/100)*M_PI),5);
        float z=round(sin((i/100)*M_PI),5);
        perfil.push_back(_vertex3f(x/2,y/2,z/2));
    }
    this->ChangeREV(perfil,100);
}

_Esfera::_Esfera(int n){
    vector<_vertex3f> perfil;
    for(int i = 100; i >= 0; i--){
        float x=0;
        float y=round(cos((i/100)*M_PI),5);
        float z=round(sin((i/100)*M_PI),5);
        perfil.push_back(_vertex3f(x/2,y/2,z/2));
    }
    this->ChangeREV(perfil,n);
}

_Esfera::_Esfera(int n,int _k){
    float k = static_cast<float>(_k);
    k-=1;
    vector<_vertex3f> perfil;
    for(int i = k; i >= 0; i--){
        float x=0;
        float y=round(cos((i/k)*M_PI),5);
        float z=round(sin((i/k)*M_PI),5);
        perfil.push_back(_vertex3f(x/2,y/2,z/2));
    }
    this->ChangeREV(perfil,n);
}


void _Esfera::Recalc(int n,int _k){
    float k = static_cast<float>(_k);
    k-=1;
    vector<_vertex3f> perfil;
    for(int i = k; i >= 0; i--){
        float x=0;
        float y=round(cos((i/k)*M_PI),5);
        float z=round(sin((i/k)*M_PI),5);
        perfil.push_back(_vertex3f(x/2,y/2,z/2));
    }
    this->ChangeREV(perfil,n);
}