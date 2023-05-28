# Grafos II

* **Grafo Suficientemente Conexo:** Grafo cuyas aristas se encuentran en la mismas componente conexa. Cabe mencionar que pueden existir nodos aislados y el grafo seguira siendo suficientemente conexo.
* **Camino Euleriano:** Camino que pasa por cada arista una y solo una vez. Notemos que como requisito el grafo debe tener dos nodos de grado impar, el inicio y final.
* **Ciclo Euleriano:** Camino cerrado que recorre cada arista exactamente una vez. Notemos que como requisito todos los nodos del grafo deben tener grado par.
* **Teorema:** Un grafo G=(V, E) suficientemente conexo con todos los grados de verties pares tiene un ciclo euleriano.
* **Teorema:** Un grafo G=(V, E) suficientemente conexo con dos vertices de grado impar y todos los demas de grado par tiene un camino euleriano.

## Algoritmos Utiles

* [**Algoritmo de Dijkstra**](./grafos_II/Algoritmo_de_Dijkstra.cpp)
* [**Algoritmo de Kruskal**](./grafos_II/Algoritmo_de_Kruskal.cpp)
* [**Estructura Union Find**](./grafos_II/Union_Find.cpp)

## Grafo bipartito

Un grafo bipartito es un grafo que cumple que se pueden dividr todos los nodos en dos conjuntos tal que los nodos de un conjunto solo estan conectados con los nodos del otro conjunto, o sea, no existe ninguna arista que conecte dos nodos del mismo conjunto. Podemos chequear si un grafo es bipartito si sus nodos pueden ser coloreados usando dos colores de manera que no existan dos nodos adyacentes pintados del mismo color.

El siguiente codigo sirve para poder determinar si un grafo es bipartito a partir de cualquier nodo pues el objetivo es revisar que sus vecinos sean del otro tipo, luego los vecinos de los vecinos tienen que ser del primer tipo de nuevo y asi:

**OBS: Esta solucion considera grafos no dirigidos.**

```cpp
vector<bool> visitado(n,false);

// Iniciamos asumiendo que es bipartito
bool bipartito = true;

// Aquí guardamos el número del conjunto para cada nodo
// Como son solo dos usaremos 1 y 2
vector<int> conjunto(n);

// Pasamos por todos los nodos
for (int i=0;i<n;i++){

    // Si no hemos visitado este nodo hay que checkear su componente conexa
    // Esto no sería necesario si el grafo fuera conexo
    // En ese caso bastaría con un BFS desde un nodo cualquiera
    if (!visitado[i]){
        // Inicializamos la fuente con i
        int s = i;
        queue<int> bfs;
        bfs.push(s);
        visitado[s] = true;
        
        // Le asignamos un conjunto, este no importa porque
        // estos conjuntos se determinan de acuerdo a la
        // búsqueda, no hay otra opción realmente
        conjunto[s] = 1;
        
        // Parte el BFS
        while (!bfs.empty()){
            int nodo = bfs.front();
            bfs.pop();
            for (int vecino:gr[nodo]){
            
                // Si no ha sido visitado...
                if (!visitado[vecino]){
                    bfs.push(vecino);
                    visitado[vecino] = true;
                    
                    // Le asignamos el conjunto opuesto
                    if (conjunto[nodo] == 1){
                        conjunto[vecino] = 2;
                    } else {
                        conjunto[vecino] = 1;
                    }
                    
                // Si ya lo visitamos...
                } else {
                    // Y tienen el mismo conjunto asignado...
                    if (conjunto[nodo] == conjunto[vecino]){
                        // ¡No es bipartito!
                        bipartito = false;
                    }
                }
            }
        }
    }
    }

if (bipartito){
    cout<<"Es bipartito\n";
} else {
    cout<<"No es bipartito\n";
}
```

## Caminos y ciclos eulerianos

Un camino eulariano es un camino que ocupa todas las aristas de un grafo sin repetirlas (**cada arista se visita una vez**). Ademas, este camino sera un ciclo euleriano si tambien es un ciclo.

**OBS: No confundir con un camino hamiltoniano donde cada nodo se visita una sola vez.**

### Ciclo euleriano

El siguiente codigo permite encontrar un ciclo euleriano:

```cpp
#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> edges;
vector <vector <int>> adj;
vector <int> ans; // El ciclo euleriano quedará acá
vector <bool> used;

void dfs(int u){
    while(adj[u].size() > 0){
        int e = adj[u].back();
        adj[u].pop_back(); // Borramos la arista para que no se vuelva a usar
        if(used[e]) continue; // Si ya fue usada (desde el otro lado, la inversa) la ignoramos
        used[e] = 1;
        // El XOR es para encontrar el que es distinto. Los dos que son iguales se cancelan entre si.
        // Es lo mismo que (edges[i].first == u ? edges[i].second : edges[i].first)
        dfs(edges[e].first ^ edges[e].second ^ u);
        ans.push_back(u);
    }
}

int main(){
    /*
        Leer el input. A diferencia de una lista de adyacencia común,
        en la lista de adyacencia de un nodo no guardaremos los índices
        de los otros nodos, si no que guardaremos los índices de las aristas,
        y las aristas están en 'edges'
        Input de ejemplo:
        n m
        u1 v1
        u2 v2
        ...
        um vm
    */
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    used.assign(m, false);
    for(int i=0, u, v; i<m; i++){
        cin >> u >> v;
        u--; v--; // borrar si ya vienen indexados de cero
        edges.emplace_back(u,v);
        adj[u].push_back(i);
        adj[v].push_back(i); // quitar si el grafo es dirigido
    }
    for(int i=0; i<n; i++){
        if(adj[i].size() % 2 != 0){
            // Hay un nodo de grado impar. No existe ciclo euleriano
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    ans.push_back(0);
    dfs(0);
    if(ans.size() != m+1){
        // El ciclo encontrado no usa todas las aristas. El grafo no tiene todas las aristas en la misma
        // componente conexa.
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int x : ans){
        cout << x+1 << ' ';
    }
    cout << '\n';
    return 0;
}
```