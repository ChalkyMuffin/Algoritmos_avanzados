#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definicion de la estructura Edge para representar una arista
struct Edge {
    int src, dest, weight;

    // Sobrecarga del operador '<' para comparar aristas por peso
    bool operator<(const Edge& other) const {
        return weight > other.weight;  // Para que la priority_queue funcione como una min-heap
    }
};

// Definicion de la clase Graph para representar un grafo
class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adjList;  // Lista de adyacencia (destino, peso)

    // Constructor que recibe el numero de vertices e inicializa el grafo
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    // Metodo para agregar una arista al grafo
    void addEdge(int src, int dest, int weight, bool directed = false) {
        adjList[src].emplace_back(dest, weight);
        if (!directed) {
            adjList[dest].emplace_back(src, weight);
        }
    }

    // Metodo que implementa el algoritmo de Prim para encontrar el MST
    void primMST() {
        priority_queue<Edge> pq;
        vector<bool> inMST(V, false);
        vector<Edge> result;

        // Añadir cualquier nodo como punto de inicio
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            Edge current = pq.top();
            pq.pop();

            int u = current.dest;

            // Verificar si el vertice ya esta en el MST
            if (inMST[u]) {
                continue;
            }

            // Agregar la arista al MST
            inMST[u] = true;
            result.push_back(current);

            // Agregar las aristas adyacentes al priority queue
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (!inMST[v]) {
                    pq.push({u, v, weight});
                }
            }
        }

        // Imprimir el resultado
        cout << "Aristas seleccionadas en el MST:\n";
        int totalCost = 0;
        for (const auto& edge : result) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
            totalCost += edge.weight;
        }

        cout << "Costo total del arbol: " << totalCost << "\n";
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
        graphDirected.addEdge(src, dest, weight, true);
    }

    inputFileDirected.close();

    // Imprimir el resultado del grafo dirigido
    cout << "Resultado del grafo dirigido:\n";
    graphDirected.primMST();
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
    graphUndirected.primMST();

    return 0;
}
