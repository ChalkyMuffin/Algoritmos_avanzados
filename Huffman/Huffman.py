import collections
import heapq

#Complejidad: O(n)


# Clase nodo que representa un nodo en el árbol de Huffman
class Nodo:
    def __init__(self, caracter, prob):
        self.caracter = caracter  
        self.prob = prob  
        self.tag = ""  
        self.right = None  
        self.left = None 

# Clase arbol que representa un árbol de Huffman
class Arbol:
    def __init__(self, raiz):
        self.raiz = raiz 

  # Uso de recursividad para sacar codigo de Huffman
    def _get_codigos_rec(self, nodo, codigo_actual, codigos):
        if nodo is None:
            return
        if nodo.caracter:
            codigos[nodo.caracter] = codigo_actual
        self._get_codigos_rec(nodo.left, codigo_actual + "0", codigos)
        self._get_codigos_rec(nodo.right, codigo_actual + "1", codigos)

  
    # Método para obtener los códigos de Huffman
    def get_codigos(self, raiz):
        codigos = {}
        codigo_actual = ""
        self._get_codigos_rec(raiz, codigo_actual, codigos)
        return codigos

# Arboles con minimas posibilidades
def min_probs(arboles):
    min1, min2 = 0, 1

    if arboles[min1].raiz.prob > arboles[min2].raiz.prob:
        min1, min2 = min2, min1

    for i in range(2, len(arboles)):
        if arboles[i].raiz.prob < arboles[min1].raiz.prob:
            min2 = min1
            min1 = i
        elif arboles[i].raiz.prob < arboles[min2].raiz.prob:
            min2 = i

    return min1, min2

# Fusiona dos arboles
def merge_trees(a, b):
    prob_sum = a.raiz.prob + b.raiz.prob
    new_root = Nodo(None, prob_sum)
    new_root.left = a.raiz
    new_root.right = b.raiz
    a.raiz.tag = "0"
    b.raiz.tag = "1"
    return Arbol(new_root)

# Función para crear el árbol de Huffman
# Input: Los simbolos de alfabeto y las probabilidades de cada carácter de aparecer.
# Regresa: Arbol de huffman
def crea_huffman_tree(caracteres, probabilidades):
    arboles = [(prob, Arbol(Nodo(char, prob))) for char, prob in zip(caracteres, probabilidades)]

  # Empieza con las posibilidades mas bajas
    heapq.heapify(arboles)

    while len(arboles) > 1:
        prob1, arbol1 = heapq.heappop(arboles)
        prob2, arbol2 = heapq.heappop(arboles)

        prob_sum = prob1 + prob2
        new_root = Nodo(None, prob_sum)
        new_root.left = arbol1.raiz
        new_root.right = arbol2.raiz
        arbol1.raiz.tag = "0"
        arbol2.raiz.tag = "1"

        arbol_fusionado = Arbol(new_root)
        heapq.heappush(arboles, (prob_sum, arbol_fusionado))

    return arboles[0][1]

# Función para codificar un string
# Input: El string a codificar y la tabla de códigos generada a partir del árbol
# Regresa: String codificado
def encoding(cadena, tabla_codigos):
    try:
        codigo = ""

        for caracter in cadena:
            # Genera y agrega los codigos a la variable para despues ponerlo en el txt
            codigo += tabla_codigos[caracter]

        return codigo
    except KeyError:
        print(f"El '{caracter}' no tiene un código en la tabla de códigos.")
        return ""

# Función para decodificar una cadena codificada
# Input: La cadena codificada y el árbol de Huffman
# Regresa: La cadena decodificada
def decode(cadena_codificada, arbol_huffman):
    # Inicializamos variables para rastrear la posición actual en la cadena y el árbol
    posicion = 0
    nodo_actual = arbol_huffman.raiz
    cadena_decodificada = ""

    # Recorremos la cadena codificada
    while posicion < len(cadena_codificada):
        bit_actual = cadena_codificada[posicion]

        # Si el bit es "0", vamos al hijo izquierdo del nodo actual
        if bit_actual == "0":
            nodo_actual = nodo_actual.left
        # Si el bit es "1", vamos al hijo derecho del nodo actual
        elif bit_actual == "1":
            nodo_actual = nodo_actual.right

        # Verificamos si llegamos a una hoja del árbol (carácter decodificado)
        if nodo_actual.caracter is not None:
            # Agregamos el carácter decodificado a la cadena resultante
            cadena_decodificada += nodo_actual.caracter
            # Reiniciamos el nodo actual al nodo raíz para decodificar el
          # siguiente carácter
            nodo_actual = arbol_huffman.raiz

        # Avanzamos a la siguiente posición en la cadena
        posicion += 1

    return cadena_decodificada

# Función que lee el archivo, reemplaza los caracteres que pueden traer problemas y cuenta los caracteres para sacar las probabilidades
# Input: Archivo de texto a leer.
# Regresa:  tupla con alfabeto y probabilidades de cada caracater
def calcular_probabilidades_archivo(archivo):
    try:
        with open(archivo, 'r', encoding='utf-8') as file:
            texto = file.read().replace('\n', '').replace('\r', '')
            
            # Elimina acentos y convierte todo a minúsculas
            texto = texto.lower()
            texto = texto.replace('á', 'a').replace('é', 'e').replace('í', 'i').replace('ó', 'o').replace('ú', 'u')
          #Muestra el texto con los reemplazos deseados
            # print("Texto leído del archivo:\n", texto)


          
            
            # Calcula las probabilidades de cada carácter y genera el alfabeto
            conteo_caracteres = collections.Counter(texto)
            total_caracteres = len(texto)
            alfabeto = list(conteo_caracteres.keys())
            probabilidades = {char: count / total_caracteres for char, count in conteo_caracteres.items()}

            print("Probabilidades:\n" , probabilidades)
            
            
            return alfabeto, probabilidades
    except FileNotFoundError:
        print(f"El archivo '{archivo}' no fue encontrado.")



archivo_texto = 'texto.txt'  
alfabeto, probabilidades_caracteres = calcular_probabilidades_archivo(archivo_texto)

# Crear el árbol de Huffman 
arbol_huffman = crea_huffman_tree(alfabeto, probabilidades_caracteres)

tabla_codigos = arbol_huffman.get_codigos(arbol_huffman.raiz)

archivo_salida = 'texto_codificado.txt'

# Lee el archivo de entrada para codificar su contenido
with open(archivo_texto, 'r', encoding='utf-8') as file:
    texto_a_codificar = file.read().replace('\n', '').replace('\r', '')
    texto_a_codificar = texto_a_codificar.lower()
    texto_a_codificar = texto_a_codificar.replace('á', 'a').replace('é', 'e').replace('í', 'i').replace('ó', 'o').replace('ú', 'u')

# Codificar el texto
texto_codificado = encoding(texto_a_codificar, tabla_codigos)

# Guarda el texto codificado en el archivo de salida
with open(archivo_salida, 'w', encoding='utf-8') as file:
    file.write(texto_codificado)


opcion = int(input("Elige 1 para codificar o 2 para decodificar: "))

if (opcion == 1):
  prueba = str(input("Escribe el string a codificar: "))
  prueba_codificada = encoding(prueba, tabla_codigos)
  print("String codificada:", prueba_codificada)
elif (opcion == 2):
  prueba = str(input("Escribe el string a decodificar: "))
  prueba_decodificada = decode(prueba, arbol_huffman)
  print("Cadena decodificada:", prueba_decodificada)
