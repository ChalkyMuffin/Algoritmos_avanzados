#include <iostream>
#define n 4
using namespace std;

//nQueenBack
//Es el problema de colocar n reinas en un tablero de ajedrez de nxn
//Complejidad O(N!)


//Funcion booleana que revisa antes de poner una reina, si alguna otra reina puede comersela ya sea en linea recta, diagonal arriba o diagonal abajo
//Input: La matriz del tablero, la fila y la columna donde se va a poner la reina
//Regresa true si el lugar en el que se pondra la reina esta a salvo de que otras reinas se la coman, false si alguna reina se la puede comer
bool Sobrevive(int tablero[n][n], int fila, int col) {

    // En el caso de que se encuentre en linea recta en frente de una reina
    for (int i = 0; i < col; i++) {
        if (tablero[fila][i]) {
            return false;
        }
    }

    // En caso de que se encuentre en diagonal de arriba
    for (int i = fila, j = col; i >= 0 && j >= 0; i--, j--) {
        if (tablero[i][j]) {
            return false;
        }
    }

    // En caso de encontrarse en diagonal abajo
    for (int i = fila, j = col; i < n && j >= 0; i++, j--) {
        if (tablero[i][j]) {
            return false;
        }
    }

    //Si esta a salvo de otras reinas
    return true;
}

//Funcion que al cooperar con Sobrevive() introduce las reinas en los lugares donde ninguna reina pueda ser comida por otra reina, despues de introducir una reina utiliza la recursividad para moverse de columna en columna y asi pasar el dato a Sobrevive()
//Input: La matriz del tablero y la columna en la que se quiere iniciar, para intentar con todas col debe tener el valor de 0
//Regresa: El tablero con las reinas
bool nQueens(int tablero[n][n], int col) {

    //Caso base, todas las reinas se han colocado
    if (col >= n) {
        return true; 
    }

    //Loop para poner las reinas, llama a Sobrevive() para saber si es seguro poner una reina ahi, es decir para saber que no se la comerian
    for (int i = 0; i < n; i++) {
        //Llama a Sobrevive() para saber si es seguro poner una reina ahi
        if (Sobrevive(tablero, i, col) == true) {

            //Es seguro asi que pone la reina
            tablero[i][col] = 1; 

            //Llamada recursiva, si tiene una solucion se toma
            if (nQueens(tablero, col + 1) == true) {
                return true; 
            }

            //Hace el backtrack en la siguiente fila
            tablero[i][col] = 0; 
        }
    }

    //Si no se encuentra forma
    return false; 
}



int main() {
    //Inicializa un tablero 4x4 con puros 0
    int tablero[4][4] = {0};

    nQueens(tablero, 0);
   

    // Imprime el tablero final
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}