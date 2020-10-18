
arr2 = [ 2, 2, 2, 2 ] 

arr3 = [ 20, 30, 2, 2, 2,10 ,5] 

#20 2 2 5

#30 2 10

arreglo= [ 8, 15, 3, 7 ]
def cartas(arreglo):
    n=len(arreglo)
    matriz = [[0 for i in range(n)]for i in range(n)]
    for i in range(n):
        matriz[i][i]=arreglo[i]
    cartasEscogidas=[]
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
            for a in matriz:
              for b in a:
                  print(b,end =" ")
              print()
            print("\n")
    return matriz[0][n-1], cartasEscogidas
print("el juego perfecto sumaría: ",cartas(arr3))


