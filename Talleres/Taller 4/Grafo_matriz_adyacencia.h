#ifndef GRAFO_MATRIZ_ADYACENCIA_H_INCLUDED
#include <bits/stdc++.h>
#define GRAFO_MATRIZ_ADYACENCIA_H_INCLUDED
#include "Grafo.h"

class Grafo_Matriz_Adyacencia: public Graph{

public:
    vector<vector<long>> matrizAdyacencia;

    vector<Vertice> vecinos(Vertice v){
        vector<Vertice> vec;
        for(int i = 0; i < vertices.size(); i++){
            if(vertices[i].id != v.id && this->matrizAdyacencia[v.id][i]!=INT_MAX)
            {
                vec.push_back(vertices[i]);
            }
        }
    return vec;
    }

    long costoArista(Vertice v1,Vertice v2){
        return this->matrizAdyacencia[v1.id][v2.id];
    }

    void anadirVertice(Vertice* toAdd){
      int verticesSize = this->vertices.size();
      bool flag=true;
      if(verticesSize==0){
            toAdd->id =0;
      this->vertices.push_back(*toAdd);
      vector<long>x(1,INT_MAX);
       this->matrizAdyacencia.push_back(x);
       return;
      }
      toAdd->id = verticesSize;
      for(int i=0;i<verticesSize;i++)
         this->matrizAdyacencia[i].push_back(INT_MAX);
      vector<long>x(verticesSize+1,INT_MAX);
      this->matrizAdyacencia.push_back(x);
      this->vertices.push_back(*toAdd);
    }

    void anadirArista(Vertice src, Vertice dest, long dist){
       this->matrizAdyacencia[src.id][dest.id] = dist;
    }

};

#endif // GRAFO_H_INCLUDE 
