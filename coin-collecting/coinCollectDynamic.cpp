#include <iostream>
#define n 5
#include <vector>
using namespace std;
//Complejidad: O(n^2)





//Funcion que examina toda la matriz para analizar las posibilidades del mejor caso para obtener la mayor cantidad de monedas solo pudiendo moverse abajo y a la derecha
//Input: La matriz de las monedas
//Regresa: La mayor cantidad de monedas que se pueden conseguir en una sola ida
int F(int C[n][n]) {

    //Vector de matriz para las subsoluciones
    vector<vector<int>> dynamic(n, vector<int>(n, 0));
    dynamic[0][0] = C[0][0];


//Inicializa la primera columna en sentido vertical
    for (int i = 0; i < n; ++i) {
        dynamic[i][0] += C[i][0];

    }
    
    //Inicializa la primera fila en sentido horizontal
    for (int j = 0; j < n; ++j) {
        dynamic[0][j] += C[0][j];

    }
    
    //Llenar la matriz de dynamic utilizando la relación de recurrencia con la matriz C
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            // Valor máximo acumulado considerando las dos direcciones posibles
            cout <<"dynamic[i-1][j] " << dynamic[i-1][j] << endl;
            cout << "dynamic[i][j-1] " << dynamic[i][j-1] << endl;
            dynamic[i][j] = max(dynamic[i-1][j], dynamic[i][j-1]) + C[i][j];
            cout <<"Escogio " << max(dynamic[i-1][j], dynamic[i][j-1]) << endl;
        }
    }
    
    // En [n-1][n-1] que en este caso es [4][4] ya habra acabado el recorrido por lo que en esa posicion le pedimos retornar su valor obtenido
    
    return dynamic[n-1][n-1];
}

int main ()
{

//Se crea la matriz que simula el camino representando los espacion vacios con 0 y los espacios con monedas con 1
int C[5][5]={{0, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {1, 0, 0, 0, 1}};

    //Muestra la matriz de una forma parecida a el camino de la imagen del problema
     for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            //cout << "a[" << i << "][" << j << "]: ";

            cout << C[i][j] << " " ;
        }
        cout << endl;
     }

    cout << F(C);
    cout << " = Monedas maximas posibles de una sola vuelta"<< endl;

    return 0;
}
