#ifndef GRAFO_LISTA_ARISTAS_H_INCLUDED
#define GRAFO_LISTA_ARISTAS_H_INCLUDED
#include "Grafo.h"

using namespace std;
class Grafo_Lista_Aristas : public Graph{

    map< pair<Vertice,Vertice> , long> l_ar;
    bool equals(Vertice x, Vertice y){
        return x.marca == y.marca;
    }

    vector<Vertice> listaVecinos(Vertice v)
    {
        vector<Vertice> result;
        for (std::map<pair<Vertice,Vertice>, long>::iterator it=l_ar.begin(); it!=l_ar.end(); ++it){
            if(equals(it->first.first, v)){
                result.push_back(it->first.second);
            }
        }
        return result;
    }

    long costoArista(Vertice v1,Vertice v2 ){
        pair<Vertice,Vertice>x(v1,v2);
        if(l_ar.find(x) == l_ar.end())
            return INT_MAX;
        return l_ar[x];
    }
     void anadirVertice(Vertice* nuevoVert){
         nuevoVert->marca = this->vertices.size();
         vertices.push_back(*nuevoVert);
    }

    void anadirArista(Vertice inicio, Vertice fin, long dist){
         l_ar.insert(make_pair( make_pair(inicio,fin),dist ));
    }

};



#endif // GRAFO_LISTA_ARISTAS_H_INCLUDED
