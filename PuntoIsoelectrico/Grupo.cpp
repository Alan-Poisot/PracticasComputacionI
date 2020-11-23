#include "Grupo.h"

int Grupo::getCarga(float ph){
    return carga+(ph<pKa||(ph-pKa<0.0001));
}
float Grupo::getpKa(){
    return pKa;
}