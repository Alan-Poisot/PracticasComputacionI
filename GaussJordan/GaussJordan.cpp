#include <iostream>
#include <array>

// Añadir std para fácil llamado de funciones
using namespace std;

//// Declaración de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz & miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz & miMatriz);

template <typename matriz>
void GaussJordan(matriz & miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz & miMatriz);


int main()
{
    // Definimos el número de variables de nuestro sistema
    const int variables = 3;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    // Imprimimos la solución de la matriz
    ImprimirSolucion(miMatriz);

    return 0; // Indicamos que salimos del programa con éxito
}

/* 
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
*/
template <typename matriz>
void LlenarMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}

/* 
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}

/*
Imprime en pantalla la solución para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout<<"x"<<i<<" = "<<miMatriz[i][variables]<<"\n";
    }
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz & miMatriz)
{
    int variables = miMatriz.size();
    int columnas=variables+1;
    bool valid=1;
    float mult=0;
    //Primero se realiza el algoritmo de arriba hacia abajo
    for (int ren = 0; ren < variables-1 ; ren++) {
        //Se comprueba que haya un coeficiente distinto de cero para el renglón correspondiente y se intenta arreglar
        if(miMatriz[ren][ren]==0){
            valid=0;
            for (int i = ren; i < variables; i++) {
                if(miMatriz[i][ren]!=0){
                    for (int j = ren; j < columnas; j++) {
                        miMatriz[ren][j]+=miMatriz[i][j];
                    }
                    valid=1;
                }
            }
            // Si no hay otro renglón con coeficiente inicial igual a cero, no se puede resolver el sistema
            if(!valid){
                cout<<"El sistema no tiene solución única";
                for (int i = 0; i < variables; i++) {
                    miMatriz[variables][i]=0;
                }
                return;
            }
        }
        //Si no hay problema, se procede a normalizar los coeficientes con respecto al primero del renglón 
        mult=miMatriz[ren][ren];
        for (int i = ren; i < columnas; i++) {
            miMatriz[ren][i]/=mult;
        }
        //finalmente, se resta el renglón actual de cada uno de los que están debajo, multiplicado por el primer elemento de cada uno de ellos
        for (int i = ren+1; i < variables; i++) {
            mult=miMatriz[i][ren];
            for (int j = ren; j < columnas; j++) {
                miMatriz[i][j]-=mult*miMatriz[ren][j];
            }//ImprimirMatriz(miMatriz); cout<<"---------------------------------\n"; //Si se desea ver el proceso paso a paso
        }
    }
    //Se normaliza la última fila
    miMatriz[variables-1][variables]/=miMatriz[variables-1][variables-1];
    miMatriz[variables-1][variables-1]/=miMatriz[variables-1][variables-1];
    
    //Luego, se realiza el algoritmo de abajo hacia arriba
    for (int ren = variables-1; ren >= 0; ren--) {
        for (int i = ren-1; i >=0; i--) {
            mult=miMatriz[i][ren];
            for (int j = ren; j < columnas; j++) {
                miMatriz[i][j]-=mult*miMatriz[ren][j];
            }
        }//ImprimirMatriz(miMatriz); cout<<"----------------------------------------\n"; //Si se desea ver el proceso paso a paso
    }
}
