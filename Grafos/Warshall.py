# Función para encontrar las distancias mínimas entre todos los pares de nodos en un grafo ponderado
def warshall(graph):
    n = len(graph)
    
    # Inicializar la matriz de distancias con infinito para representar la ausencia de conexión
    dist = [[float('inf')] * n for _ in range(n)]

    # Inicializar los valores de la diagonal principal a 0, ya que la distancia de un nodo a sí mismo es 0
    for i in range(n):
        dist[i][i] = 0

    # Asignar los pesos de las aristas conocidos
    for u, v, weight in graph:
        dist[u][v] = weight

    # Calcular las distancias mínimas utilizando la funcion warshall
    for k in range(n):
        for i in range(n):
            for j in range(n):
                # Actualizar la distancia si encontramos un camino más corto a través del nodo intermedio k
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    return dist

# Función para leer el grafo desde un archivo
def read_graph(file_name):
    with open(file_name, 'r') as file:
        vertices = int(file.readline())
        edges = [tuple(map(int, line.split())) for line in file]

    return vertices, edges

# Función para imprimir los nodos alcanzables desde cada nodo con sus respectivos caminos
def print_paths(distances):
    for i in range(len(distances)):
        # Obtener los nodos alcanzables desde el nodo i
        reachable_nodes = [j for j in range(len(distances[i])) if distances[i][j] != float('inf') and i != j]
        # Convertir los índices de nodos a letras para imprimir de manera más amigable
        node_str = ", ".join(chr(ord('a') + node) for node in reachable_nodes)
        print(f"{chr(ord('a') + i)} tiene un camino hacia: {node_str}")

# Función principal
def main():
    # Grafo dirigido
    vertices, edges_directed = read_graph("grafo-dirigido.txt")
    print("Resultado del grafo dirigido:")
    distances_directed = warshall(edges_directed)
    print_paths(distances_directed)
    print()

    # Grafo no dirigido
    vertices, edges_undirected = read_graph("grafo-no-dirigido.txt")
    print("Resultado del grafo no dirigido:")
    distances_undirected = warshall(edges_undirected)
    print_paths(distances_undirected)

# Ejecutar la función principal si el script se ejecuta directamente
if __name__ == "__main__":
    main()
