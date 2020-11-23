#include "Molecula.h"



void Molecula::AgregarGrupo(Grupo x){
    grupos.push_back(x);
    numGrupos++;
}

float Molecula::CalcularPuntoIsoelectrico(){

    float limInf=0, limSup=0;
    float ph=0.0;
    int sum=-1000;
    int c=0;
    /*while (sum!=0){
        ph=grupos[c].getpKa();
        sum=cargaNeta(ph);
        c++;
    }
    limInf=ph;*/
    for(int i=0;i<numGrupos;i++){
        ph=grupos[i].getpKa();
        sum=cargaNeta(ph);
        if(sum==0){
            limSup=ph;
        } else{
            if (cargaNeta(ph+0.01)==0){
                limInf=ph;
            }
        }
    }

    return (limInf+limSup)/2;
}

int Molecula::cargaNeta(float ph){
    int sum=0;
    for (int j = 0; j < numGrupos; ++j) {
        sum+=grupos[j].getCarga(ph);
    }
    return sum;
}