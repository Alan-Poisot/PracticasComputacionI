#ifndef CARGAELECTRICA_GRUPO_H
#define CARGAELECTRICA_GRUPO_H

#include <string>

using namespace std;

class Grupo{
private:
    string nombre;
    float pKa;
    int carga;
public:
    Grupo() { nombre = ""; pKa = 0;carga=0; };
    Grupo(string nom, float pk, int c) { nombre = nom; pKa = pk; carga=c; }
    int getCarga(float ph);
    float getpKa();

};


#endif //CARGAELECTRICA_GRUPO_H
