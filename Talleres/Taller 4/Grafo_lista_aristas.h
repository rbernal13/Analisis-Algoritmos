#ifndef GRAFO_LISTA_ARISTAS_H_INCLUDED
#define GRAFO_LISTA_ARISTAS_H_INCLUDED
#include "Grafo.h"

using namespace std;
class Grafo_Lista_Aristas : public Graph{

    map< pair<Vertice,Vertice> , long> listaAristas;
    bool equals(Vertice v1, Vertice v2){
        return v1.marca == v2.marca;
    }

    vector<Vertice> listaVecinos(Vertice v)
    {
        vector<Vertice> result;
        for (std::map<pair<Vertice,Vertice>, long>::iterator it=listaAristas.begin(); it!=listaAristas.end(); ++it){
            if(equals(it->first.first, v)){
                result.push_back(it->first.second);
            }
        }
        return result;
    }

    long costoArista(Vertice v1,Vertice v2 ){
        pair<Vertice,Vertice>arist(v1,v2);
        if(listaAristas.find(arist) == listaAristas.end())
            return INT_MAX;
        return listaAristas[arist];
    }
     void anadirVertice(Vertice* nuevoVert){
         nuevoVert->marca = this->vertices.size();
         vertices.push_back(*nuevoVert);
    }

    void anadirArista(Vertice inicio, Vertice fin, long distancia){
         listaAristas.insert(make_pair( make_pair(inicio,fin),distancia ));
    }

};



#endif // GRAFO_LISTA_ARISTAS_H_INCLUDED
