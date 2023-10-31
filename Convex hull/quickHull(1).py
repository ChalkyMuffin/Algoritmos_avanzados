
import matplotlib.pyplot as plt
import numpy as np




def quickhull(points):
    """Algoritmo de QuickHull para encontrar la envolvente convexa de un conjunto de puntos.

    Args:
        points (list): Lista de puntos.

    Returns:
        list: Lista de puntos que conforman la envolvente convexa.
    """
    convex_hull = []
    # Se obtienen los puntos con coordenada x minima y maxima
    min_x = min(points, key=lambda p: p[0])
    max_x = max(points, key=lambda p: p[0])
    # Se obtienen los puntos que se encuentran sobre la recta que une los puntos minimo y maximo
    convex_hull.append(min_x)
    convex_hull.append(max_x)
    points.remove(min_x)
    points.remove(max_x)
    # Se obtienen los puntos que se encuentran sobre la recta que une los puntos minimo y maximo
    left_points = []
    right_points = []
    for point in points:
        if is_left(min_x, max_x, point):
            left_points.append(point)
        else:
            right_points.append(point)
    # Se obtienen los puntos que se encuentran sobre la recta que une los puntos minimo y maximo
    find_hull(left_points, min_x, max_x, convex_hull)
    find_hull(right_points, max_x, min_x, convex_hull)
    return convex_hull

def is_left(p1, p2, p3):
    """Determina si un punto se encuentra a la izquierda de una recta.

    Args:
        p1 (list): Punto inicial de la recta.
        p2 (list): Punto final de la recta.
        p3 (list): Punto a evaluar.

    Returns:
        bool: True si el punto se encuentra a la izquierda de la recta, False en caso contrario.
    """
    return ((p2[0] - p1[0]) * (p3[1] - p1[1])) > ((p2[1] - p1[1]) * (p3[0] - p1[0]))

def find_hull(points, p1, p2, convex_hull):
    """Encuentra los puntos que conforman la envolvente convexa.

    Args:
        points (list): Lista de puntos.
        p1 (list): Punto inicial de la recta.
        p2 (list): Punto final de la recta.
        convex_hull (list): Lista de puntos que conforman la envolvente convexa.
    """
    if len(points) == 0:
        return
    # Se obtiene el punto mas lejano de la recta que une los puntos minimo y maximo
    farthest_point = max(points, key=lambda p: distance(p1, p2, p))
    convex_hull.insert(convex_hull.index(p2), farthest_point)
    points.remove(farthest_point)
    # Se obtienen los puntos que se encuentran a la izquierda de la recta que une los puntos minimo y maximo
    left_points = []
    for point in points:
        if is_left(p1, farthest_point, point):
            left_points.append(point)
    # Se obtienen los puntos que se encuentran a la izquierda de la recta que une los puntos minimo y maximo
    right_points = []
    for point in points:
        if is_left(farthest_point, p2, point):
            right_points.append(point)
    # Se obtienen los puntos que se encuentran a la izquierda de la recta que une los puntos minimo y maximo

    find_hull(left_points, p1, farthest_point, convex_hull)
    find_hull(right_points, farthest_point, p2, convex_hull)

def distance(p1, p2, p3):
    a = p2[1] - p1[1]
    b = p1[0] - p2[0]
    c = (p2[0] * p1[1]) - (p1[0] * p2[1])

    return abs(a*p3[0] + b*p3[1] + c) / ((a**2 + b**2)**0.5)


def draw_hull( puntos, elegidos, start ):
  n = len(puntos)               # contamos cuantos puntos son
  colors = np.random.rand(n)    # un arreglo de n colores

  # Un scatter plot grafica:
  # - una lista de puntos, si le pasamos 2 listas con coordenadas x, y
  # - o un solo punto, si le pasamos 2 valores x, y
  # Grafica todos los puntos semitrasparentes, y los elegidos en color solido
  plt.scatter([p[0] for p in elegidos], [p[1] for p in elegidos])
  plt.scatter([p[0] for p in puntos], [p[1] for p in puntos], c=colors, alpha=0.5)  # alpaha agrega trasparencia

  plt.scatter( start[0], start[1] ) # graficamos el punto de referencia

  # plot grafica segmentos de recta
  # si le pasamos dos listas con coordenadas x, y
  elegidos.append(elegidos[0])         # Para que el ultimo punto conecte con el primero, lo agregamos al final de la lsita
  plt.plot([p[0] for p in elegidos] , [p[1] for p in elegidos] ,  linestyle="-")   # este tipo de linestyle es una linea continua

  plt.show()

def main():
    #Toma los puntos dados en el archivo 'puntos-n8.txt'
    with open('puntos-n8.txt', 'r') as file:
        lines = file.readlines()
    
    point_lines = lines[1:]
    
    points = []
    
    for line in point_lines:
        x, y = map(float, line.strip().split('\t'))
        points.append((x, y))
    
    convex_hull = quickhull(points)
    convex_hull.append(convex_hull[0])
    print(convex_hull)
    draw_hull(points, convex_hull, points[0])

if __name__ == "__main__":
    main()

