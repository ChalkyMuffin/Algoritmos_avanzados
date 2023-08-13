#include <iostream>
#include <cmath>
using namespace std;

//Closest-pair
//Complejidad: O(n^2)

//Funcion para calcular la distancia
//Input: Direcciones en 'x' y 'y' de ambos puntos
//Regresa: El resultado del calculo de la distancia entre ambos puntos
int distancia(int x1, int x2, int y1, int y2)
{
    double distancia = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distancia;
}

int main()
{
    //Se declara con numero absurdamente grande para poder insertar el primer resultado de la distancia y hacer comparacion con el resto
    int distanciaMinima = 99999;

    int p1x; 
    int p2x;
    int p1y;
    int p2y;

    // Coordenadas de puntos en x
    int px[4] = {12, 20, 25, 26};

    // Coordenadas de puntos en y
    int py[4] = {3, 7, 19, 18};
    int n = 4;

    //Itera por ambas listas tomando los valores de x1 y y1 con 'i' y a su derecha los valores de x2 y y2 con 'j' para darselos a la funcion de distancia y al final compara el resultado del calculo de cada distancia y guarda el mas pequeño, al comparar con todos los datos a sus derechas, se cambia el valor de x1 y y1 por los siguientes numeros a su derecha y se repite el proceso hasta acabar la lista 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d;

            //Guarda el resultado de cada calculo para compararlo con la distancia minima actual
            d = distancia(px[i], px[j], py[i], py[j]);

            //Compara el calculo de distancia de cada iteracion con la distancia minima actual
            if (d < distanciaMinima)
            {
                p1x = px[i];
                p2x = px[j];
                p1y = py[i];
                p2y = py[j];

                distanciaMinima = d;

            }
        }
    }
    cout << "La distancia minima es = " << distanciaMinima << " y es entre los puntos: [" << p1x << ", " << p1y << "] y [" << p2x << ", " << p2y << ']' << endl;

    // cout << distancia(20,25,7,19);
    return 0;
}