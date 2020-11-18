#include "Grupo.h"

int Grupo::getCarga(float ph){
    return carga+(ph<=pKa);
}
