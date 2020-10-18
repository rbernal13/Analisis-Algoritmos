def mochilaF(peso, valor, pesoMaximo):
  filas= len(peso)+1
  columnas=pesoMaximo+1
  mochila= [[0 for i in range(columnas)] for j in range(filas)]
  for i in range(1,filas):
    for j in range(1,columnas):
      #if peso[i-1] <= i and valor[i-1]>mochila[i-1][j]:
      if peso[i-1] <= j:
        #mochila[i][j]=valor[i-1]
        mochila[i][j]=max(mochila[i-1][j],valor[i-1]+mochila[i-1][j-peso[i-1]])
        #mochila[i][j]=valor[i-1]+ mochila[i-1][j-peso[i-1]]
      else:
        mochila[i][j]= mochila[i-1][j]
  for i in mochila:
    for j in i:
      print(j,end =" ")
    print() 
  maleta=[]
  i=filas-1
  j=columnas-1

  pesoT = 0

  # Backtrack - Devolver el valor de cada uno de los elementos de la lista
  while(i>0):
    pesoT += peso[i-1]
    print(peso[i-1])
    print(pesoT)
    if pesoT <= pesoMaximo:
      maleta.append(i-1)
      i -= 1
      j -= peso[i-1]
    else:
      pesoT -= peso[i-1]
      i -= 1
  print(maleta)

# Ejemplo 1

valor=[2,2,4,5,3]    
peso=[3,1,3,4,2]
pesoMaximo=7
mochilaF(peso,valor, pesoMaximo)

# Ejemplo 2

# Ejemplo 3

# Ejemplo 4

# Ejemplo 5