#ifndef MOLECULA_H
#define MOLECULA_H

#include <string>
#include <vector>

#include "Grupo.h"

using namespace std;
class Molecula
{
    public:
        Molecula(string nom) {name = nom; numGrupos=0;}
        void AgregarGrupo(Grupo x);
        float CalcularPuntoIsoelectrico();
        int cargaNeta(float ph);
    private:
        string name;
        int numGrupos;
        vector<Grupo> grupos;
};

#endif // MOLECULA_H
