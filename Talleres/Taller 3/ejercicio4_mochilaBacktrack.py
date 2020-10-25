import numpy as np

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
    aux = np.array(mochila)
    print(aux)
    print("\n")
  
  aux = np.array(mochila)
  print("Resultado final \n", aux)
  
  maleta=[]
  i=filas-1
  j=columnas-1

  pesoT = 0

  # Backtrack - Devolver el valor de cada uno de los elementos de la lista
  while(i>0):
    pesoT += peso[i-1]
    #print(peso[i-1])
    #print(pesoT)
    if pesoT <= pesoMaximo:
      maleta.append(i-1)
      i -= 1
      j -= peso[i-1]
    else:
      pesoT -= peso[i-1]
      i -= 1
  #print("Los articulos en la mochila son ", maleta)
  return mochila[filas-1][columnas-1],maleta

# Ejemplo 1
print("# Ejemplo 1 \n")

valor=[2,2,4,5,3]    
peso=[3,1,3,4,2]
pesoMaximo=7
print("Los articulos iniciales son ", valor," y el peso de cada articulo es ", peso,". La mochila tiene un peso maximo de ", pesoMaximo)
resulMejorTotal, resulMaleta = mochilaF(peso,valor, pesoMaximo)
print("El mejor valor obtenible en la mochila es", resulMejorTotal," con los sigueintes articulos ", resulMaleta)

# Ejemplo 2
print("# Ejemplo 2 \n")

valor=[2,3,1,4]    
peso=[4,5,3,7]
pesoMaximo=5
print("Los articulos iniciales son ", valor," y el peso de cada articulo es ", peso,". La mochila tiene un peso maximo de ", pesoMaximo)
resulMejorTotal, resulMaleta = mochilaF(peso,valor, pesoMaximo)
print("El mejor valor obtenible en la mochila es", resulMejorTotal," con los sigueintes articulos ", resulMaleta)

# Ejemplo 3
print("# Ejemplo 3 \n")

valor=[1,6,10,16]    
peso=[1,2,3,5]
pesoMaximo=7
print("Los articulos iniciales son ", valor," y el peso de cada articulo es ", peso,". La mochila tiene un peso maximo de ", pesoMaximo)
resulMejorTotal, resulMaleta = mochilaF(peso,valor, pesoMaximo)
print("El mejor valor obtenible en la mochila es", resulMejorTotal," con los sigueintes articulos ", resulMaleta)
