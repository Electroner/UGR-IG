#include <iostream>
#include <math.h>
using namespace std;

int main(){

    //obtener los puntos de un perfil de una circunferencia x,y,z
    for(int i=180;i>=0;i--){
        float x=0;
        float y=cos(i*M_PI/180);
        float z=sin(i*M_PI/180);
        cout<< "_vertex3f("<<x/2<<","<<y/2<<","<<z/2<<"),";
    }

    return 0;
}