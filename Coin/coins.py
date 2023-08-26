
# Simplemente recursivo, top-down 
def coins (C, n, K): 
	if K == 0:				#	caso base
		return 1
	elif n <= 0 or K < 0:	#	descartamos casos invalidos
		return 0
	else:
		# casos donde usamos C[n-1],   mas
		# casos donde no usamos C[n-1]
		return coins(C, n, K - C[n-1]) + coins(C, n-1, K) 




C = [1, 2, 5, 10]
n = len(C)

K = 5

print( "M(",n,",",K,") = ", coins(C, n, K) )


##-------Con memoization, T es la tabla de resultados de subproblemas
#def coins_memo (C, n, K, T): 
#	if K == 0:
#		T[n][K] = 1
#		return T[n][K]

#	elif n <= 0 or K < 0:
#		return 0

#	elif T[n][K] != -1:		# si ya esta calculado, 
#		return T[n][K]		# los overlaping subproblems no se recalculan

#	else:				# si no esta calculado, hay que calcularlo recursivamente
#		T[n][K] = coins_memo(C, n, K- C[n-1], T) + coins_memo(C, n-1, K, T) 
#		return T[n][K]

## creamos una tabla de -1, con K+1 cols y n+1 filas
#T_memo = [[-1 for i in range(K+1)] for j in range(n+1)]  

#print( "M_m(",n,",",K,") = ", coins_memo(C, n, K, T_memo) )



#-------Con tabulacion, iterativo bottom-up 

#def coins_tabu (C, n, K ):
#	T_tabu = [[0 for i in range(K+1)] for j in range(n+1)]  

#	# 	equivalente del caso base
#	T_tabu[0][0] = 1

#	for i in range(1, n + 1):
#		for j in range (0, K + 1):
			
#			T_tabu[i][j] += T_tabu[i-1][j]      # inicia con el valor de cuando no usamos la moneda

#			if  j - C[i-1] >= 0:
#				T_tabu[i][j] += T_tabu[i][j - C[i-1]]

#	return T_tabu[n][K]

#print( "M_t(",n,",",K,") = ", coins_tabu(C, n, K) )