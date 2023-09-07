#include <iostream>
#define n 5
#include <vector>
using namespace std;
//Complejidad: O(n^2)


//Se crea la matriz que simula el camino representando los espacion vacios con 0 y los espacios con monedas con 1
//La matriz es la misma que la del problema pero volteada 180 grados para adaptarlo correctamente a la funcion
//int C[5][5]={{1, 0, 0, 0, 1}, {0, 0, 1, 0, 0}, {0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {1, 0, 0, 0, 0}};


//Funcion que examina toda la matriz para analizar las posibilidades del mejor caso para obtener la mayor cantidad de monedas solo pudiendo moverse abajo y a la derecha, o arriba y a la derecha de la perspectiva del robot
//[i, j] es la posicion en la que inicia
//Input: Coordenadas de posicion inicial i y j
//Regresa: La mayor cantidad de monedas que se pueden conseguir en una sola ida
int F(int C[n][n]) {

    vector<vector<int>> dinamM(n, vector<int>(n, 0));

    dinamM[0][0] = C[0][0];


// Inicializar la primera numna: acumular monedas hacia abajo
    for (int i = 1; i < n; ++i) {
        dinamM[i][0] = dinamM[i-1][0] + C[i][0];
    }
    
    // Inicializar la primera fila: acumular monedas hacia la derecha
    for (int j = 1; j < n; ++j) {
        dinamM[0][j] = dinamM[0][j-1] + C[0][j];
    }
    
    // Llenar la tabla dinamM utilizando la relación de recurrencia
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            // Valor máximo acumulado considerando las dos direcciones posibles
            dinamM[i][j] = max(dinamM[i-1][j], dinamM[i][j-1]) + C[i][j];
        }
    }
    
    // El valor en la esquina inferior derecha contiene la solución al problema
    return dinamM[n-1][n-1];
}

int main ()
{
int C[5][5]={{0, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {1, 0, 0, 0, 1}};

    //Muestra la matriz de una forma parecida a el camino de la imagen del problema
     for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            //cout << "a[" << i << "][" << j << "]: ";

            cout << C[i][j] << " " ;
        }
        cout << endl;
     }

    //[4,4] es la posicion inicial
    cout << F(C);
    cout << " = Monedas maximas posibles"<< endl;

    return 0;
}
