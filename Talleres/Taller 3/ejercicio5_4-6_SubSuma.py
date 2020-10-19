import numpy as np

def subsecuencia_suma (S,n):
    #n = len(S) # Tamaño secuencia
    K =  sum(S) # Suma total de S
    if K%2==0:
      return 0
    subK  = K // 2 # Suma de una subsecuencia

    subP = [[False for j in range(n+1)] for i in range(subK+1)] 

    i, j = 0, 0

    for i in range(0,n+1):
        subP [0][i] = True   # En el numero 0, relleno con True

    for i in range (1,subK+1): # Recorro cada fila
      for j in range (1,n+1): # Recorro cada columna 
          subP[i][j] = subP[i][j-1]
          if i >= S[j-1]:
            subP[i][j] = (subP[i][j] or subP[i-S[j-1]][j - 1])
      aux = np.array(subP)
      print(aux)
    
    
    return subP[subK][n]



def subsecuenciaSum(S):
  n = len(S)
  res = subsecuencia_suma(S,n)
  if res == True:
    print("se puede")
  else:
    print("paila")

S = [2,1,1,1,3,1]
S1 = [2,1,1,1,3,2]

print("Para la secuencia S ", S)
subsecuenciaSum(S)

print("Para la secuencia S ", S1)
subsecuenciaSum(S1)



