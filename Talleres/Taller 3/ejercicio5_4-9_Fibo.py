def fibonacci_recursivo(n):
    return n if n < 2 else fibonacci1(n-1) + fibonacci1(n-2) # O(2^n)

def multiplicar_matriz(A, B): 
	x = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) 
	y = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) 
	z = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) 
	w = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) 
	
	A[0][0] = x 
	A[0][1] = y 
	A[1][0] = z 
	A[1][1] = w 
			
def potencia_matriz(A, n): 
	if(n <= 1): 
		return A 
	
	B = [[1, 1], [1, 0]] 
	
	potencia_matriz(A, n // 2)
	multiplicar_matriz(A, A)

	if (n%2 != 0): 
		multiplicar_matriz(A, B)  

def fibonacci_dp(n): 	
	if (n <= 1): 
		return n
	
	A = [[1, 1], [1, 0]] 
	potencia_matriz(A, n-1) 		
	
	return A[0][0] 

print(fibonacci_dp(9))