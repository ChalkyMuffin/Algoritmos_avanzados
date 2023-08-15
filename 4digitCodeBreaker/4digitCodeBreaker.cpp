#include <iostream>
#include <string>
using namespace std;
//Algoritmo individual investigado


//Adrian Cavazos Guerra - A00833841
//4digitCodeBreaker
//Complejidad: O(n!)


//Funcion que pide un string del codigo correcto e iterara hasta 10000 veces ya que la contraseña es de 4 digitos y puede usar digitos del 0 al 9 por lo tanto 10 digitos, asi que tendria que iterar 10^4 o 10000 veces a lo mucho
//Se usan strings para poder añadir ceros a la izquierda del pin de prueba, en cada iteracion buscara comprobar si ese es el pin correcto
//Input: La contraseña correcta
//Regresa: El codigo correcto encontrado o un mensaje diciendo que no se encontro el codigo
void pinBreak(const string& password) {
    for (int i = 0; i < 10000; ++i) {
        // Convierte el numero a string para poder agregarle ceros a su izquierda
        string pinPrueba = to_string(i);

        //Checa si el pin tiene 4 digitos de largo y si no lo es le va agregando ceros hasta que lo sea
        while (pinPrueba.length() < 4) {
            pinPrueba = "0" + pinPrueba;
            //cout << pinPrueba << endl;
        }

        //Checa si el pin es el correcto, si lo es lo muestra y acaba el loop
        if (pinPrueba == password) {
            cout << "Codigo correcto encontrado: " << pinPrueba << endl;
            return;
        }
    }
    cout << "Codigo no encontrado." << endl;
}

int main()
{
    string password = "0030";
    cout << "Encontrando codigo..." << endl;
    pinBreak(password);

    return 0;
}