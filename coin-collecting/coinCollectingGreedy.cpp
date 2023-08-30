#include <iostream>
using namespace std;
//Complejidad: O(2^(i+j))


//Se crea la matriz que simula el camino representando los espacion vacios con 0 y los espacios con monedas con 1
//La matriz es la misma que la del problema pero volteada 180 grados para adaptarlo correctamente a la funcion
int C[5][5]={{0, 3,	2,	3, 3},	{2,	3,	3,	2,	1},	{3,	3,	2,	2,	2},	{0,	4,	0,	2,	2},	{0,	4,	2,	2,	2}};

//int C[5][5]={{0, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {1, 0, 0, 0, 1}};

//Funcion que examina toda la matriz para analizar las posibilidades del mejor caso para obtener la mayor cantidad de monedas solo pudiendo moverse abajo y a la derecha, o arriba y a la derecha de la perspectiva del robot
//[i, j] es la posicion en la que inicia
//Input: Coordenadas de posicion inicial i y j
//Regresa: La mayor cantidad de monedas que se pueden conseguir en una sola ida
int F(int i, int j) {

    //Si el punto en la matriz es caminable
    if (i >= 0 && j >= 0) {
        //cout << "a[" << i << "][" << j << "]: " << C[i][j] << endl;

        //Funciona porque el max detecta por defecto a la primera recursion (F(i-1,j)) como mayor lo que hace que tome en cuenta F(i,j-1) haciendo que vaya solo a la derecha, en el momento que llegue a un punto del que no puede avanzar procede al F(i-1,j) lo que hace que baje y en el momento que baja hasta mas no poder se regresa a un punto a la derecha de donde bajo anteriormente porque el otro condicional hace que regrese a ese estado anterior y asi se repite mientras todo este tiempo se estan sumando las veces que se encuentra una moneda en el camino qeu se reinicia cada vez que llega a un -1 y regresa la fucion la mayor suma que logro encontrar
        return max(F(i - 1, j), F(i, j - 1)) + C[i][j];
        
    }

    //Si el punto no es caminable
    else if (i < 0 || j < 0) {
        //cout << "a[" << i << "][" << j << "]: " << endl;
        return 0;
    }
    return 0;
}

int main ()
{
    //Muestra la matriz de una forma parecida a el camino de la imagen del problema
     for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            //cout << "a[" << i << "][" << j << "]: ";

            cout << C[i][j] << " " ;
        }
        cout << endl;
     }

    //[4,4] es la posicion inicial
    cout << F(4, 4);
    cout << " = Monedas maximas posibles"<< endl;

    return 0;
}
