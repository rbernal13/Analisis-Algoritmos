import numpy as np

def cartas(arreglo):
    n=len(arreglo)
    matriz = [[0 for i in range(n)]for i in range(n)]
    for i in range(n):
        matriz[i][i]=arreglo[i]
    for corrimiento in range(1,n):
        i =0
        for j in range (corrimiento, n):
            #f1 = (i+2,j)
            #f2 = (i+1,j-1)
            #f3 = (i, j-2)
            f1 = 0
            if((i + 2) <= j): 
                f1 = matriz[i + 2][j] 
            f2 = 0
            if((i + 1) <= (j - 1)): 
                f2 = matriz[i + 1][j - 1] 
            f3 = 0
            if(i <= (j - 2)): 
                f3 = matriz[i][j - 2] 
            matriz[i][j] = max(arreglo[i] + min(f1, f2),arreglo[j] + min(f2, f3))
            i+=1
            aux = np.array(matriz)
            print(aux)
            print("\n")
    return matriz[0][n-1]

#-----------------MAIN------------------#

S1 = [10, 30, 5, 8]

S2 = [20, 30, 2, 2, 2, 10] 

S3 = [8, 15, 3, 7]

print("Para la secuencia", S1 ,", la sumatoria de la secuencia optima de cartas mas altas para el primer jugador seria ",cartas(S1))


