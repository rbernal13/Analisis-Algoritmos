#ifndef GRAFO_MATRIZ_ADYACENCIA_H_INCLUDED
#include <bits/stdc++.h>
#define GRAFO_MATRIZ_ADYACENCIA_H_INCLUDED
#include "Grafo.h"

class Grafo_Matriz_Adyacencia: public Graph{

public:
    vector<vector<long>> matrizAdyacencia;

    vector<Vertice> listaVecinos(Vertice v){
        vector<Vertice> vec;
        for(int i = 0; i < vertices.size(); i++){
            if(vertices[i].marca != v.marca && this->matrizAdyacencia[v.marca][i]!=INT_MAX)
            {
                vec.push_back(vertices[i]);
            }
        }
    return vec;
    }

    long costoArista(Vertice v1,Vertice v2){
        return this->matrizAdyacencia[v1.marca][v2.marca];
    }

    void anadirVertice(Vertice* nuevoVert){
      int verticesSize = this->vertices.size();
      bool flag=true;
      if(verticesSize==0){
            nuevoVert->marca =0;
      this->vertices.push_back(*nuevoVert);
      vector<long>x(1,INT_MAX);
       this->matrizAdyacencia.push_back(x);
       return;
      }
      nuevoVert->marca = verticesSize;
      for(int i=0;i<verticesSize;i++)
         this->matrizAdyacencia[i].push_back(INT_MAX);
      vector<long>x(verticesSize+1,INT_MAX);
      this->matrizAdyacencia.push_back(x);
      this->vertices.push_back(*nuevoVert);
    }

    void anadirArista(Vertice inico, Vertice fin, long dist){
       this->matrizAdyacencia[inico.marca][fin.marca] = dist;
    }

};

#endif // GRAFO_H_INCLUDE 
