arr = [1,3,4]

def sumarFormas(n):
    if n == 0:
        return 1
    if n < 0:
        return 0
    count=0
    for j in range(0,len(arr)):
        count += sumarFormas(n-arr[j])
    return count

def sumarNumero(n):
    suma = [0 for i in range(0, n + 1)] 

    suma[0] = suma[1] = suma[2] = 1
    suma[3] = 2
    
    print(suma)
    for i in range(4, n + 1): 
        suma[i] = suma[i - 1] + suma[i - 3] + suma[i - 4] 
        print(suma)
      
    return suma[n] 

N = 7
print("El numero es ",N, " y la cantidad de formas de expresalor como una suma de 1,3 y 4 son ",sumarNumero(N))