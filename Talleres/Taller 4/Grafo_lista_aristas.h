#ifndef GRAFO_LISTA_ARISTAS_H_INCLUDED
#define GRAFO_LISTA_ARISTAS_H_INCLUDED
#include "Grafo.h"

using namespace std;
class Grafo_Lista_Aristas : public Graph{

    map< pair<Vertice,Vertice> , long> l_ar;
    bool equals(Vertice x, Vertice y){
        return x.id == y.id;
    }

    vector<Vertice> vecinos(Vertice v)
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
     void anadirVertice(Vertice* toAdd){
         toAdd->id = this->vertices.size();
         vertices.push_back(*toAdd);
    }

    void anadirArista(Vertice src, Vertice dest, long dist){
         l_ar.insert(make_pair( make_pair(src,dest),dist ));
    }

};



#endif // GRAFO_LISTA_ARISTAS_H_INCLUDED
