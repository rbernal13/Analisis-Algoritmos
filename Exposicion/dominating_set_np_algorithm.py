def esDominante(G,Vj,j): #Vj es el certificado/solucion para Vertex Cover NP
	Grafo H = generarGrafo(G) # Genera el nuevo grafo añadiendo los nuevos vertices a los originales
	V = getVertices(H)
	return verificarDominante(V,Vj,j)

def verificarDominante(V,Vk,k):
    esDominante=False
	if (len(Vk)==k):
		esDominante=True
		for v in V:
			if v not in Vk:
				if (not adyacente(v,Vk)):
					esDominante=False
					return esDominante
	return esDominante
		
def adyacente(v,Vk):
	existeArista = True
	for each b in Vk:
		if(g.costoArista(v,b) < Inf):
			return existeArista
		else:
			existeArista = False
	return existeArista




		