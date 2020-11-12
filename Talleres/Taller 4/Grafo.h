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
    int marca;
    string contenido;
    

    bool operator < (const Vertice& vex) const
    {
        return marca< vex.marca;
    }
    bool operator == (const Vertice& vex) const
    {
        return contenido == vex.contenido;
    }
    Vertice (string valr)
    {
        contenido = valr;
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
    virtual vector<Vertice> listaVecinos(Vertice v) = 0;
    virtual long costoArista(Vertice v1,Vertice v2)= 0;
    virtual void anadirVertice(Vertice *nuevoVert) = 0;
    virtual void anadirArista(Vertice inicio, Vertice fin, long dist) =0;

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

    list<Vertice>bProfundidad(Vertice v){
        list<Vertice>verts;
        vector<bool>arr1(this->vertices.size(),false);
        vector<Vertice>y = listaVecinos(v);
        arr1[v.marca] = true;
        verts.push_back(v);
        stack<Vertice>pileta;
        for(Vertice ver:y)
            pileta.push(ver);
        while(!pileta.empty())
        {
            Vertice aux = pileta.top();
            pileta.pop();
            if(arr1[aux.marca]==false)
            {
                arr1[aux.marca]= true;
                verts.push_back(aux);
                vector<Vertice>y = listaVecinos(aux);
                for(Vertice ver:y)
                    pileta.push(ver);
            }
        }
        return verts;
    }

    map<int, int> bAncho(Vertice v)
    {
        queue<Vertice> cola;
        map<int, int> mapa;
        cola.push(v);
        for(int i=0; i<vertices.size(); i++)
            mapa[vertices[i].marca] = INT_MAX;
        mapa[v.marca] = 0;
        cout<<"anterior: "<<mapa.size()<<endl;
        system("PAUSE");
        while (!cola.empty())
        {
            Vertice aux = cola.front();
            cola.pop();
            vector<Vertice>y = listaVecinos(aux);
            for(Vertice ver:y)
            {
                if (mapa[ver.marca] == INT_MAX)
                {
                    cout<<"si entra"<<endl;
                    mapa[ver.marca] = mapa[aux.marca] + 1;
                    cola.push(ver);
                }
            }
        }
        return mapa;
    }

    map<int,int> dijkstra(Vertice v)
    {
        map<int, int> mapa;
        for(int i=0; i<vertices.size(); i++)
            mapa[vertices[i].marca] = INT_MAX;
        mapa[v.marca] = 0;
        priority_queue <pair<int,Vertice>, vector< pair<int,Vertice> >, comparar > cola;
        cola.push(make_pair(0,v));
        while(!cola.empty())
        {
            pair<int,Vertice> top = cola.top();
            cola.pop();
            int distancia = top.first;
            Vertice ver = top.second;
            if(distancia == mapa[ver.marca])
            {
                vector<Vertice>y = listaVecinos(ver);
                for (Vertice x : y)
                {
                    int costo = costoArista(ver,x);
                    if(mapa[ver.marca]+costo < mapa[x.marca])
                    {
                        mapa[x.marca] = mapa[ver.marca]+costo;
                        cola.push(make_pair(mapa[x.marca],x));
                    }
                }
            }
        }
        return mapa;
    }

    map<int,long> bellmanFord(Vertice v)
    {
        map< int, long > mapa;
        int sizes = vertices.size();
        for(int i=0; i<sizes; i++)
        {
            mapa[vertices[i].marca] = INT_MAX;
        }
        mapa[v.marca] = 0;

        vector< pair< long,pair<Vertice,Vertice> > > aristas  = getAristas();
        for(int i=0; i<sizes-1; i++)
        {
            for(int j = 0; j < aristas.size(); j++)
            {
                Vertice src = aristas[j].second.first;
                Vertice dest = aristas[j].second.second;
                long peso = aristas[j].first;
                long x = mapa[dest.marca];
                long y = mapa[src.marca] + peso;
                mapa[dest.marca] = min(x,y);
            }
        }


        for(int j = 0; j < aristas.size(); j++)
        {
            Vertice src = aristas[j].second.first;
            Vertice dest = aristas[j].second.second;
            long peso = aristas[j].first;
            long x = mapa[dest.marca];
            long y = mapa[src.marca] + peso;
            if(y < x)
            {
                cout<<"-1, ciclo negativo"<<endl;
                return mapa;
            }
        }
        return mapa;
    }

    long kruskals()
    {
        long mst_cost = 0;
        vector< pair< long,pair<Vertice,Vertice> > >listAristas = getAristas();
        priority_queue< pair<long, pair<int,int> > >EdgeList;
        for(int i=0; i<listAristas.size(); i++)
            EdgeList.push(  make_pair(    -(listAristas[i].first),make_pair(  listAristas[i].second.first.marca,listAristas[i].second.second.marca)     )    );
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

    long vert_minimo(vector<bool>aux, vector<long>costoVert)
    {
        int indice = 0,mini = INT_MAX;
        for (int j = 0; j <vertices.size(); j++)
        {
            if (aux[j] == false && costoVert[j] <= mini)
            {
                mini = costoVert[j], indice = j;
            }
        }
        return indice;
    }

    void algthPrim()
    {
        vector<int> vertAnterior(vertices.size(),-1);
        vector<long>costoVert(vertices.size(),INT_MAX);
        vector<bool>aux(vertices.size(),false);
        costoVert[0] = 0;
        vertAnterior[0] = -1;
        for(int i=0; i<vertices.size(); i++)
        {
            long indice = vert_minimo(aux,costoVert);
            aux[indice] = true;

            for(int j =0 ; j<vertices.size(); j++)
            {
                if(j != indice && aux[j] == false && costoArista(vertices[indice],vertices[j]) < costoVert[j])
                {
                    vertAnterior[j] = indice;
                    costoVert[j] = costoArista(vertices[indice],vertices[j]);
                }
            }

        }

        for (int i = 1; i < vertices.size(); i++)
            cout<<vertAnterior[i]<<" - "<<i<<", costo: "<<costoArista(vertices[i],vertices[vertAnterior[i]])<<" \n";
    }



    void jugar(int fila,vector<int>&column,list< vector<int> > &resul)
    {
        if(fila == 8)
        {
            resul.push_back(column);
        }
        else
        {
            for(int i=0; i<8; i++)
            {
                column.push_back(i);
                if(validarRes(column))
                {
                    jugar(fila+1,column,resul);
                }
                column.pop_back();
            }
        }
    }



    bool validarRes(vector<int>&column)
    {
        int fila = column.size()-1;
        for(int i = 0; i<fila; i++)
        {
            int diferencia = abs(column[i] - column[fila]);
            if(diferencia == 0 || diferencia == (fila - i))
            {
                return false;
            }
        }
        return true;
    }

    list< vector<int> > reina()
    {
        list< vector<int> > res;
        vector<int>y;
        jugar(0,y,res);
        return res;
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
            cout<<"entra"<<endl;
            pair<Vertice,Vertice> l = cola.top();
            int d;
            int c;
            stringstream cont1(l.first.contenido);
            cont1>>c;
            stringstream cont2(l.second.contenido);
            cont2>>d;
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

};


#endif // GRAFO_H_INCLUDED


