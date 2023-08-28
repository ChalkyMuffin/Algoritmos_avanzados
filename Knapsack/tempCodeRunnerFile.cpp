#include <iostream>
#include <vector>
using namespace std;
//Knapsack
class Gem {
  public:
    string Name;
    int value;
    int weight;
};

void Knapsack(Gem gemas[]){
        int n = sizeof(gemas);
        vector<Gem> gemasObtenidas;
        int valorFinal = 0;
        int pesoFinal = 0;

    for (int i = 0; i < n; i++){
        gemasObtenidas.push_back(gemas[i]);

        valorFinal += gemas[i].value;
        pesoFinal += gemas[i].weight;

        //Al momento que se sobrepase el limite de peso que es 10, checara tambien si la gema anterior tenia un valor menor a la nueva y si el descartar la anterior liberaria el suficiente peso para llevar esta ultima gema mas valiosa
        if (pesoFinal > 10 && gemas[i-1].value < gemas[i].value && pesoFinal - gemas[i-1].weight <= 10){    
            gemasObtenidas.pop_back();
            gemasObtenidas.pop_back();
            gemasObtenidas.push_back(gemas[i]);

            valorFinal -= gemas[i-1].value;
            pesoFinal -= gemas[i-1].weight;

        }

    }

    for (int i = 0; i < gemasObtenidas.size(); i++){
        cout << gemasObtenidas[i].Name << endl;
    }
        cout << "Valor: " << valorFinal << " Peso: " << pesoFinal << endl;

}

int main ()
{
    Gem Verde, Azul, Rojo, Rosa;
    Verde.Name = "Verde"; 
    Verde.value = 7;
    Verde.weight = 2;

    Azul.Name = "Azul";
    Azul.value = 8;
    Azul.weight = 3;

    Rojo.Name = "Rojo";
    Rojo.value = 10;
    Rojo.weight = 4;

    Rosa.Name = "Rosa";
    Rosa.value = 12;
    Rosa.weight = 5;

    Gem gemas[4] = {Verde, Azul, Rojo, Rosa};

    Knapsack(gemas);


    
    return 0;





}