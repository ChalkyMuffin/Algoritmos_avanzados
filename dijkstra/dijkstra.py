

def findMin ( distancia, procesado):
	index = -1 
	minC = float('inf')

	for i in range(len(procesado)):
		if distancia[i] < minC and procesado[i] == 0:
			index = i
			minC = distancia[i]	
	return index 
 

def dikjstra (G):
	origen = 0

	distancia = [ float('inf') for i in range(0, len(G)) ]
	distancia[origen] = 0

	procesado = [ 0 for i in range(0, len(G)) ]
	desde = [ 0 for i in range(0, len(G)) ]

	print(distancia)
	print(desde)

	for i in G:
		u = findMin(distancia, procesado)
		procesado[u] = 1

		print("\n")
		for j in G[u]:
			vecino = j[0]
			costo = j[1]
			nueva_distancia = distancia[u] + costo
			
			print(u , j, nueva_distancia)
			
			if nueva_distancia < distancia[vecino]:
				distancia[vecino] = nueva_distancia
				desde[vecino] = u

	print(distancia)
	print(desde)


A = 0
B = 1
C = 2
D = 3
E = 4


V = [A, B, C, D, E]

G1 = {	A: [[B, 4], [C, 2] ],
		B: [[C, 3], [D, 2], [E, 3] ],
		C: [[B, 1], [D, 4], [E, 5] ],
		D: [],
		E: [[D, 1]]  }

dikjstra(G1)


#G = nx.Graph() 
