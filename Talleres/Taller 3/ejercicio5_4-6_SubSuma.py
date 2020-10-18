
def subsecuencia_suma (S,n):
    #n = len(S) # Tamaño secuencia
    K =  sum(S) # Suma total de S
    if K%2==0:
      return 0
    subK  = K // 2 # Suma de una subsecuencia

    P = [[False for j in range(subK+1)] for i in range(n+1)] 

    i, j = 0, 0

    for i in range(1,n+1):
        P [i][0] = True   # En el numero 0, relleno con True

    for i in range (1,n+1): # Recorro cada fila
      for j in range (1,subK+1): # Recorro cada columna 
        if (j < S[i-1]):
          P[i][j] = P[i-1][j]
        else:
          P[i][j] = (P[i-1][j] or P[i-1][j - S[i-1]])
    return P[n][subK]

#S = [2,1,1,1,3,1]
S = [2,1,1,1,3,2]
n = len(S)
res = subsecuencia_suma(S,n)
if res == True:
  print("se puede")
else:
  print("paila")

