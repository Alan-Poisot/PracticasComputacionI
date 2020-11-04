#include "Punto.h"
#include <cmath>

void Punto2D::SetPosicion(float a, float b){
    x=a;
    y=b;
    return;
}


void Punto2D::Trasladar(float a, float b){
    x+=a;
    y+=b;
    return;
}


void Punto2D::RotarRespectoAlOrigen(float a){
    float xp=x;
    x=x*cos(a*3.14159265359/180)-y*sin(a*3.14159265359/180);
    y=xp*sin(a*3.14159265359/180)+y*cos(a*3.14159265359/180);
    return;
}


void Punto2D::Escalar(float a, float b){
    x*=a;
    y*=b;
    return;
}


float Punto2D::GetX(){
    return x;
}


float Punto2D::GetY(){
    return y;
}
