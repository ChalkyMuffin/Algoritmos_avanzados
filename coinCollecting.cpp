#include <iostream>
#include <vector>

using namespace std;


//Complejidad O(n*m)
int maxCoins(vector<vector<int>>& recorrido) {
    int fl = recorrido.size(); // Número de filas en la cuadrícula
    int col = recorrido[0].size(); // Número de columnas en la cuadrícula
    
    // Matriz para las sub-soluciones
    vector<vector<int>> dinamM(fl, vector<int>(col, 0));
    
    // Inicializar la primera celda con su valor de moneda
    dinamM[0][0] = recorrido[0][0];
    
    // Inicializar la primera columna: acumular monedas hacia abajo
    for (int i = 1; i < fl; ++i) {
        dinamM[i][0] = dinamM[i-1][0] + recorrido[i][0];
    }
    
    // Inicializar la primera fila: acumular monedas hacia la derecha
    for (int j = 1; j < col; ++j) {
        dinamM[0][j] = dinamM[0][j-1] + recorrido[0][j];
    }
    
    // Llenar la tabla dinamM utilizando la relación de recurrencia
    for (int i = 1; i < fl; ++i) {
        for (int j = 1; j < col; ++j) {
            // Valor máximo acumulado considerando las dos direcciones posibles
            dinamM[i][j] = max(dinamM[i-1][j], dinamM[i][j-1]) + recorrido[i][j];
        }
    }
    
    // El valor en la esquina inferior derecha contiene la solución al problema
    return dinamM[fl-1][col-1];
}

int main() {
    vector<vector<int>> recorrido = {
        {0,0,0,0,1},
        {0,1,0,1,0},
        {0,0,0,1,0},
        {0,0,1,0,0},
        {1,0,0,0,1}
    };

    int r = maxCoins(recorrido);
    cout << "Monedas recogidas: " << r << endl;

    return 0;
}
