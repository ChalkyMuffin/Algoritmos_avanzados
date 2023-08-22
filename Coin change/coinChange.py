def coins_memo (C, n, K, T):
    if K == 0:
        T[n][K] = 1
        return T[n][K]
    elif n <= 0 or K < 0:
        return 0
    else:

        if T[n][K] != 1:
            return T[n][K]
        else:
            T[n][K] = coins_memo(C,n,K-C[n-1], T) + coins_memo(C, n-1, K, T)
            return T[n][K]


C = [1,2,5,10]
n = len(C)
K = 5

T = [ [-1 for i in range (n+1)] for j in range (K+1)]
T[0][0] = 1