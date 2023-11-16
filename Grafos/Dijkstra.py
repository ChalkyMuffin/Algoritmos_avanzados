import heapq

# Clase para representar un grafo
class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.adjList = [[] for _ in range(vertices)]

    # Metodo para agregar una arista al grafo
    def add_edge(self, src, dest, weight, directed=False):
        self.adjList[src].append((dest, weight))
        if not directed:
            self.adjList[dest].append((src, weight))

    # Algoritmo de Dijkstra para encontrar los caminos mas cortos
    def dijkstra(self, start):
        pq = [(0, start, [])]  # (costo acumulado, nodo actual, camino)
        distances = [float('inf')] * self.V
        distances[start] = 0

        while pq:
            current_dist, current, path = heapq.heappop(pq)

            if current_dist > distances[current]:
                continue

            for neighbor, edge_weight in self.adjList[current]:
                new_dist = distances[current] + edge_weight
                new_path = path + [(current, neighbor, edge_weight)]

                if new_dist < distances[neighbor]:
                    distances[neighbor] = new_dist
                    heapq.heappush(pq, (new_dist, neighbor, new_path))

        return distances, path

# Funcion para leer un grafo desde un archivo
def read_graph(file_name):
    with open(file_name, 'r') as file:
        vertices = int(file.readline())
        graph = Graph(vertices)

        for line in file:
            src, dest, weight = map(int, line.split())
            graph.add_edge(src, dest, weight)

    return graph

# Funcion para imprimir los caminos mas cortos
def print_paths(distances):
    for i, (distance, path) in enumerate(distances):
        if i != start_vertex:
            total_cost = sum(edge[2] for edge in path)
            path_str = ", ".join(f"{chr(ord('a') + src)}({weight})" for src, _, weight in path)
            print(f"{chr(ord('a') + start_vertex)} ... {chr(ord('a') + i)}: {path_str} : {total_cost}")

# Funcion principal
def main():
    # Grafo dirigido
    graph_directed = read_graph("grafo-dirigido.txt")
    print("Resultado del grafo dirigido:")
    global start_vertex  # Variable global para acceder desde la funcion print_paths
    start_vertex = 0  
    distances_directed = [graph_directed.dijkstra(i) for i in range(graph_directed.V)]  # Excluir el nodo origen de los caminos
    print_paths(distances_directed)
    print()

    # Grafo no dirigido
    graph_undirected = read_graph("grafo-no-dirigido.txt")
    print("Resultado del grafo no dirigido:")
    distances_undirected = [graph_undirected.dijkstra(i) for i in range(graph_undirected.V)]  # Excluir el nodo origen de los caminos
    print_paths(distances_undirected)

if __name__ == "__main__":
    main()
