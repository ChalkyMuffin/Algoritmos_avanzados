def floyd(graph):
    # Obtener el numero de nodos en el grafo
    n = len(graph)
    
    # Inicializar la matriz de distancias con infinito
    dist = [[float('inf')] * n for _ in range(n)]

    # Inicializar la matriz de rutas intermedias con None
    path = [[None] * n for _ in range(n)]

    # Inicializar la matriz de distancias con los pesos de las aristas conocidos
    for u, v, weight in graph:
        dist[u][v] = weight
        # El nodo anterior al nodo v en la ruta mas corta desde u hasta v es u
        path[u][v] = u

    # Calcular las distancias minimas y actualizar las rutas intermedias
    for k in range(n):
        for i in range(n):
            for j in range(n):
                # Si hay un camino mas corto de i a j pasando por k
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    # Actualizar el nodo intermedio en el camino mas corto de i a j
                    path[i][j] = k

    # Imprimir el resultado
    for i in range(n):
        for j in range(n):
            print(f"Costo de camino mas corto desde {chr(ord('a') + i)} hasta {chr(ord('a') + j)}: {dist[i][j]}")

# Leer el grafo desde un archivo
def read_graph(file_name):
    with open(file_name, 'r') as file:
        vertices = int(file.readline())
        edges = [tuple(map(int, line.split())) for line in file]

    return vertices, edges

def main():
    # Grafo dirigido
    vertices, edges_directed = read_graph("grafo-dirigido.txt")
    print("Resultado del grafo dirigido:")
    floyd(edges_directed)
    print()

    # Grafo no dirigido
    vertices, edges_undirected = read_graph("grafo-no-dirigido.txt")
    print("Resultado del grafo no dirigido:")
    floyd(edges_undirected)

if __name__ == "__main__":
    main()
