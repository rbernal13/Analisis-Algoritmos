#fibonaci O(2^n)
def fibonacci1(n):
    return n if n < 2 else fibonacci1(n-1) + fibonacci1(n-2)
print(fibonacci1(7))

#fibonaci O(log n)
def fibonacci2(n): 	
	Q = [[1, 1], 
		[1, 0]] 
	if (n == 0): 
		return 0
	potencia(Q, n) 		
	return Q[0][0] 
	
def multiplicar(Q, M): 
	x = (Q[0][0] * M[0][0] + Q[0][1] * M[1][0]) 
	y = (Q[0][0] * M[0][1] + Q[0][1] * M[1][1]) 
	z = (Q[1][0] * M[0][0] + Q[1][1] * M[1][0]) 
	w = (Q[1][0] * M[0][1] + Q[1][1] * M[1][1]) 
	Q[0][0] = x 
	Q[0][1] = y 
	Q[1][0] = z 
	Q[1][1] = w 
			
def potencia(Q, n): 
	if( n == 0 or n == 1): 
		return 
	M = [[1, 1], 
		[1, 0]] 
	potencia(Q, n // 2)
	multiplicar(Q, Q)
	if (n % 2 != 0): 
		multiplicar(Q, M)  


print(fibonacci2(7)) 