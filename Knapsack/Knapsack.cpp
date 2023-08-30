#include <iostream>
#include <vector>
using std::endl;
using std::string;
using std::cout;
using std::vector;


//Knapsack problem
//Tienes un bolso y puedes cargar maximo W = 10
//¿Cuales objetos te llevas para maximisar su valor total acumulado?


//Clase con los parametros de Name, value y weight que nos serviran para diferenciar cada objeto
class Gem {
  public:
    string Name;
    int value;
    int weight;
};

//Complejidad O(n)
//Funcion que usa la tecnica greedy para resolver Knapsack, pide un arreglo con cada una de las gemas que hay disponibles, estas gemas tienen su propio valor y peso unicos, se hace un loop en el que se colecta cada gema y se suma el valorFinal y pesoFinal, si el pesoFinal sobrepasa el limite de 10, se checa si la gema anterior vale menos que la siguiente y si ese es el caso checa si al desechar la anterior podria cargar la nueva
//Input: Arreglo con las gemas disponibles y el tamaño de este arreglo
//Regresa: El nombre de las gemas en la bolsa, el valor final y el peso final
//La funcion es greedy porque busca una mejora inmediata en la primera oportunidad que pueda venir, en este caso cambiando una gema de menor valor por una de mayor
//El caso en el que no llega al optimo con este metodo especifico es cuando haya una mejor gema que reemplazar directamente antes de la que hace que llegue a sobrepeso
void Knapsack(Gem gemas[], int n){

        //Vector para guardar las gemas y desecharlas si es necesario
        vector<Gem> gemasObtenidas;
        //Valor y peso final al que se sumaran las los respectivos valores de las gemas
        int valorFinal = 0;
        int pesoFinal = 0;

    //Pasa por toda la lista de gemas para agarrarlas
    for (int i = 0; i < n; i++){
        //Agrega gemas
        gemasObtenidas.push_back(gemas[i]);

        //Agrega el valor y peso de cada gema a la bolsa
        valorFinal += gemas[i].value;
        pesoFinal += gemas[i].weight;

        //Al momento que se sobrepase el limite de peso que es 10, checara tambien si la gema anterior tenia un valor menor a la nueva y si el descartar la anterior liberaria el suficiente peso para llevar esta ultima gema mas valiosa
        if (pesoFinal > 10 && gemas[i-1].value < gemas[i].value && pesoFinal - gemas[i-1].weight <= 10){ 

            //Elimina dos veces los datos del vector ya que pop_back() solo elimina el ultimo dato 
            gemasObtenidas.pop_back();
            gemasObtenidas.pop_back();

            //Vuelve a agregar la ultima gema
            gemasObtenidas.push_back(gemas[i]);

            //Elimina el valor y peso de la gema desechada
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
    //Inicializa cada gema
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

    //Arreglo que contiene cada gema
    Gem gemas[4] = {Verde, Azul, Rojo, Rosa};
    int n = 4;

    Knapsack(gemas,n);


    
    return 0;





}