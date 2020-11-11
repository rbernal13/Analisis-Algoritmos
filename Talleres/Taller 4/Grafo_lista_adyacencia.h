#ifndef GRAFO_LISTA_ADYACENCIA_H_INCLUDED
#define GRAFO_LISTA_ADYACENCIA_H_INCLUDED
#include "Grafo.h"

class Grafo_Lista_Adyacencia : public Graph{

public:
    map<Vertice, map<Vertice, long> > listaAdyacencia;

    vector<Vertice> vecinos(Vertice v)
    {
        vector<Vertice> result;

        for (std::map<Vertice,long>::iterator it=listaAdyacencia[v].begin(); it!=listaAdyacencia[v].end(); ++it)
            result.push_back(it->first);
        return result;
    }

    long costoArista(Vertice v1,Vertice v2){

        if(listaAdyacencia[v1].find(v2) == listaAdyacencia[v1].end())
            return INT_MAX;
        return listaAdyacencia[v1][v2];

    }

    void anadirVertice(Vertice* nuevoVer)
    {
        map<Vertice, long> x;
        nuevoVer->id = listaAdyacencia.size();
        this->listaAdyacencia.insert( std::pair<Vertice,map<Vertice, long> >(*nuevoVer,x) );
        vertices.push_back(*nuevoVer);
    }

    void anadirArista(Vertice inicio, Vertice final, long distancia){
        listaAdyacencia[inicio][final] = distancia;
    }

};


#endif // GRAFO_LISTA_ADYACENCIA_H_INCLUDED
