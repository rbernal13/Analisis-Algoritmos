#ifndef GRAFO_H_INCLUDED
#include <bits/stdc++.h>
#define GRAFO_H_INCLUDED
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define max 1000

using namespace std;


class Vertice
{
public:
    int id;
    string contenido;
    bool marca = false;

    bool operator < (const Vertice& R) const
    {
        return id< R.id;
    }
    bool operator == (const Vertice& R) const
    {
        return contenido == R.contenido;
    }
    Vertice (string val)
    {
        contenido = val;
    }
};

struct comparar
{
    bool operator()(const pair<int,Vertice>& l, const pair<int,Vertice>& r)
    {
        return l.first > r.first;
    }
};

// class Pila { 
//     int top; 

//     public: 
//         Pila(){
//              top = -1;
//         }
//         int a[max];
//         void push(int valr){
//             if(top>=max-1){
//                 cout<<"Error, fuera del rango"<<endl;
//             }else{
//                 top++;
//                 a[top]=valr;
//             }
//         }
//         void pop(){
//             if(top<=-1){
//                 cout<<"Error, fuera del rango"<<endl;
//             }else{
//                 top--;
//             }
//         }
//         int top(); 
//         bool isEmpty(); 
// };

class Graph
{

public:
    vector<Vertice>vertices;
    vector<int> pset;
    virtual vector<Vertice> vecinos(Vertice v) = 0;
    virtual long costoArista(Vertice v1,Vertice v2)= 0;
    virtual void anadirVertice(Vertice *toAdd) = 0;
    virtual void anadirArista(Vertice src, Vertice dest, long dist) =0;

    vector< pair< long,pair<Vertice,Vertice> > > getAristas()
    {
        vector< pair< long, pair<Vertice, Vertice> > > result;
        for(int i = 0; i < vertices.size(); i++)
        {
            Vertice src = vertices[i];
            for(int j = 0; j < vertices.size(); j++)
            {
                Vertice dest = vertices[j];
                long costo = costoArista(src, dest);
                if( costo != INT_MAX)
                {
                    result.push_back(make_pair(costo, make_pair(src, dest)));
                }
            }
        }
        return result;
    }

    list<Vertice>DFS(Vertice v)
    {
        list<Vertice>vertex;
        vector<bool>x(this->vertices.size(),false);
        vector<Vertice>y = vecinos(v);
        x[v.id] = true;
        vertex.push_back(v);
        stack<Vertice>pileta;
        for(Vertice ver:y)
            pileta.push(ver);
        while(!pileta.empty())
        {
            Vertice aux = pileta.top();
            pileta.pop();
            if(x[aux.id]==false)
            {
                x[aux.id]= true;
                vertex.push_back(aux);
                vector<Vertice>y = vecinos(aux);
                for(Vertice ver:y)
                    pileta.push(ver);
            }
        }
        return vertex;
    }

    map<int, int> BFS(Vertice v)
    {
        queue<Vertice> cola;
        map<int, int> mapa;
        cola.push(v);
        for(int i=0; i<vertices.size(); i++)
            mapa[vertices[i].id] = INT_MAX;
        mapa[v.id] = 0;
        cout<<"anterior: "<<mapa.size()<<endl;
        system("PAUSE");
        while (!cola.empty())
        {
            Vertice aux = cola.front();
            cola.pop();
            vector<Vertice>y = vecinos(aux);
            for(Vertice ver:y)
            {
                if (mapa[ver.id] == INT_MAX)
                {
                    cout<<"si entra"<<endl;
                    mapa[ver.id] = mapa[aux.id] + 1;
                    cola.push(ver);
                }
            }
        }
        return mapa;
    }

    map<int,int> Dijkstras(Vertice v)
    {
        map<int, int> mapa;
        for(int i=0; i<vertices.size(); i++)
            mapa[vertices[i].id] = INT_MAX;
        mapa[v.id] = 0;
        priority_queue <pair<int,Vertice>, vector< pair<int,Vertice> >, comparar > cola;
        cola.push(make_pair(0,v));
        while(!cola.empty())
        {
            pair<int,Vertice> top = cola.top();
            cola.pop();
            int distancia = top.first;
            Vertice ver = top.second;
            if(distancia == mapa[ver.id])
            {
                vector<Vertice>y = vecinos(ver);
                for (Vertice x : y)
                {
                    int costo = costoArista(ver,x);
                    if(mapa[ver.id]+costo < mapa[x.id])
                    {
                        mapa[x.id] = mapa[ver.id]+costo;
                        cola.push(make_pair(mapa[x.id],x));
                    }
                }
            }
        }
        return mapa;
    }

    map<int, long> BELLMAN_FORDS(Vertice v)
    {
        map< int, long > mapa;
        int sizes = vertices.size();
        for(int i=0; i<sizes; i++)
        {
            mapa[vertices[i].id] = INT_MAX;
        }
        mapa[v.id] = 0;

        vector< pair< long,pair<Vertice,Vertice> > > aristas  = getAristas();
        for(int i=0; i<sizes-1; i++)
        {
            for(int j = 0; j < aristas.size(); j++)
            {
                Vertice src = aristas[j].second.first;
                Vertice dest = aristas[j].second.second;
                long peso = aristas[j].first;
                long x = mapa[dest.id];
                long y = mapa[src.id] + peso;
                mapa[dest.id] = min(x,y);
            }
        }


        for(int j = 0; j < aristas.size(); j++)
        {
            Vertice src = aristas[j].second.first;
            Vertice dest = aristas[j].second.second;
            long peso = aristas[j].first;
            long x = mapa[dest.id];
            long y = mapa[src.id] + peso;
            if(y < x)
            {
                cout<<"Hay ciclo negativo"<<endl;
                return mapa;
            }
        }
        return mapa;
    }

    void initSet(int _size)
    {
        pset.resize(_size);
        REP (i, 0, _size - 1) pset[i] = i;
    }
    int findSet(int i)
    {
        return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
    }
    void unionSet(int i, int j)
    {
        pset[findSet(i)] = findSet(j);
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    long kruskals()
    {
        long mst_cost = 0;
        vector< pair< long,pair<Vertice,Vertice> > >x = getAristas();
        priority_queue< pair<long, pair<int,int> > >EdgeList;
        for(int i=0; i<x.size(); i++)
            EdgeList.push(  make_pair(    -(x[i].first),make_pair(  x[i].second.first.id,x[i].second.second.id)     )    );
        initSet(this->vertices.size());
        while (!EdgeList.empty())
        {
            pair<int, pair<int,int> > front = EdgeList.top();
            EdgeList.pop();
            if (!isSameSet(front.second.first, front.second.second))
            {
                cout << front.second.first << " - " << front.second.second << endl;
                mst_cost += (-front.first);
                unionSet(front.second.first, front.second.second);
            }
        }
        return mst_cost;
    }

    long Minimos(vector<bool>aux,vector<long>NodoCosto)
    {
        int indice = 0,mini = INT_MAX;
        for (int j = 0; j <vertices.size(); j++)
        {
            if (aux[j] == false && NodoCosto[j] <= mini)
            {
                mini = NodoCosto[j], indice = j;
            }
        }
        return indice;
    }

    void Prim()
    {
        vector<int>NodoAntecesor(vertices.size(),-1);
        vector<long>NodoCosto(vertices.size(),INT_MAX);
        vector<bool>aux(vertices.size(),false);
        NodoCosto[0] = 0;
        NodoAntecesor[0] = -1;
        for(int i=0; i<vertices.size(); i++)
        {
            long indice = Minimos(aux,NodoCosto);
            aux[indice] = true;

            for(int j =0 ; j<vertices.size(); j++)
            {
                if(j != indice && aux[j] == false && costoArista(vertices[indice],vertices[j]) < NodoCosto[j])
                {
                    NodoAntecesor[j] = indice;
                    NodoCosto[j] = costoArista(vertices[indice],vertices[j]);
                }
            }

        }

        for (int i = 1; i < vertices.size(); i++)
            cout<<NodoAntecesor[i]<<" - "<<i<<" con un Costo de: "<<costoArista(vertices[i],vertices[NodoAntecesor[i]])<<" \n";
    }



    void jugar(int fila,vector<int>&col,list< vector<int> > &resultado)
    {
        if(fila == 8)
        {
            resultado.push_back(col);
        }
        else
        {
            for(int i=0; i<8; i++)
            {
                col.push_back(i);
                if(Validar(col))
                {
                    jugar(fila+1,col,resultado);
                }
                col.pop_back();
            }
        }
    }



    bool Validar(vector<int>&col)
    {
        int fila = col.size()-1;
        for(int i = 0; i<fila; i++)
        {
            int diferencia = abs(col[i] - col[fila]);
            if(diferencia == 0 || diferencia == (fila - i))
            {
                return false;
            }
        }
        return true;
    }

    list< vector<int> > reina()
    {
        list< vector<int> > resultado;
        vector<int>y;
        jugar(0,y,resultado);
        return resultado;
    }



    void ponerTrabajos()
    {
        priority_queue <pair<Vertice,Vertice>, vector< pair<Vertice,Vertice> >, less< pair<Vertice,Vertice> > > cola;
        priority_queue <pair<Vertice,Vertice>, vector< pair<Vertice,Vertice> >, less< pair<Vertice,Vertice> > > cola_aux;
        vector<int> Trabajadores((this->vertices.size())/2,0);
        vector<int> Labor((this->vertices.size())/2,0);
        for(int i = 0; i < Trabajadores.size(); i++)
        {
            Trabajadores[i] = i+1;
            Labor[i] = i+1;
        }
        int cont = 0;
        int minimo = 0;

        for(int i = 0; i < Trabajadores.size(); i++)
        {
            int valorT = Trabajadores[Trabajadores.size()-(i+1)];

            for(int j = 0; j < Labor.size(); j++)
            {

                int valorL = Labor[j];
                cont+= valorL*valorT;
                cola_aux.push(make_pair(this->vertices[(Trabajadores.size())-(j+1)],this->vertices[(Trabajadores.size())+(valorL-1)]));
                valorT--;
            }

            if(minimo < cont)
            {
                minimo = cont;
                cola = cola_aux;
                while(!cola_aux.empty())
                {
                    cola_aux.pop();
                }
            }
            cont = 0;
        }


        cout<<"La mejor asignacion seria: "<<endl;

        while(!cola.empty())
        {
            cout<<"entro"<<endl;
            pair<Vertice,Vertice> l = cola.top();
            int d;
            int c;
            stringstream geek(l.first.contenido);
            geek>>c;
            stringstream geek2(l.second.contenido);
            geek2>>d;
            this->anadirArista(l.first,l.second,c*d);
            cola.pop();
        }
        vector< pair< long,pair<Vertice,Vertice> > > asignacion  = getAristas();
        for(int i = 0; i < asignacion.size(); i++ )
        {
            cout<<"De arista: "<<asignacion[i].second.first.contenido<< " hasta arista: "<<asignacion[i].second.second.contenido<<endl;
            cout<<"Longitud: "<<asignacion[i].first<<endl;
        }
        cout<<"costo min: "<<minimo<<endl;
    }

};


#endif // GRAFO_H_INCLUDED


