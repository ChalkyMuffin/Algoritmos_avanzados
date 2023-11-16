#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Definicion de la estructura Edge para representar una arista
struct Edge {
    int src, dest, weight;

    // Sobrecarga del operador '<' para comparar aristas por peso
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Definicion de la clase Graph para representar un grafo
class Graph {
public:
    int V;  // Numero de vertices
    vector<Edge> edges;  // Vector de aristas

    // Constructor que recibe el numero de vertices e inicializa el grafo
    Graph(int vertices) : V(vertices) {}

    // Metodo para agregar una arista al grafo
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    // Metodo que implementa el algoritmo de Kruskal para encontrar el MST
    void kruskalMST() {
        // Ordenar las aristas por peso de manera ascendente
        sort(edges.begin(), edges.end());

        vector<int> parent(V, -1);  // Vector para realizar la operacion 'find' en conjuntos disjuntos
        vector<Edge> result;  // Vector para almacenar las aristas seleccionadas en el MST

        // Iterar sobre todas las aristas ordenadas
        for (const Edge& edge : edges) {
            int rootSrc = find(parent, edge.src);
            int rootDest = find(parent, edge.dest);

            // Verificar si agregar la arista crea un ciclo en el MST
            if (rootSrc != rootDest) {
                result.push_back(edge);
                unionSets(parent, rootSrc, rootDest);
            }
        }

        // Imprimir el resultado
        cout << "Aristas seleccionadas en el MST:\n";
        int totalCost = 0;
        for (const Edge& edge : result) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
            totalCost += edge.weight;
        }

        cout << "Costo total del arbol: " << totalCost << "\n";
    }


    // Metodo para realizar la operacion 'find' en conjuntos disjuntos
    int find(vector<int>& parent, int node) {
        if (parent[node] == -1) {
            return node;
        }
        return find(parent, parent[node]);
    }

    // Metodo para realizar la operacion 'union' en conjuntos disjuntos
    void unionSets(vector<int>& parent, int root1, int root2) {
        parent[root1] = root2;
    }
};

// Funcion principal
int main() {
    // Grafo dirigido
    ifstream inputFileDirected("grafo-dirigido.txt");

    if (!inputFileDirected) {
        cerr << "No se pudo abrir el archivo del grafo dirigido.\n";
        return 1;
    }

    int verticesDirected;
    inputFileDirected >> verticesDirected;
    Graph graphDirected(verticesDirected);

    int src, dest, weight;

    // Leer aristas desde el archivo y agregarlas al grafo dirigido
    while (inputFileDirected >> src >> dest >> weight) {
        graphDirected.addEdge(src, dest, weight);
    }

    inputFileDirected.close();

    // Imprimir el resultado del grafo dirigido
    cout << "Resultado del grafo dirigido:\n";
    graphDirected.kruskalMST();
    cout << "\n";

    // Grafo no dirigido
    ifstream inputFileUndirected("grafo-no-dirigido.txt");

    if (!inputFileUndirected) {
        cerr << "No se pudo abrir el archivo del grafo no dirigido.\n";
        return 1;
    }

    int verticesUndirected;
    inputFileUndirected >> verticesUndirected;
    Graph graphUndirected(verticesUndirected);

    // Leer aristas desde el archivo y agregarlas al grafo no dirigido
    while (inputFileUndirected >> src >> dest >> weight) {
        graphUndirected.addEdge(src, dest, weight);
    }

    inputFileUndirected.close();

    // Imprimir el resultado del grafo no dirigido
    cout << "Resultado del grafo no dirigido:\n";
    graphUndirected.kruskalMST();

    return 0;
}
