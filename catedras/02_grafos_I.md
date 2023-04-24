# Grafos I

## Formas de representar un grafo en codigo

### Matriz de Adyacencia

Podemos representar un grafo con una **matriz de adyacencia** marcando con un 1 el par que representa a dos nodos unidos por una arista y 0 en caso contrario.

Pros:

* Saber si dos nodos estan conectados es $O(1)$.
* Agregar y eliminar aristas es $O(1)$.

Contras:

* Listar vecinos es $O(n)$.
* Usa mucho espacio, $O(n^2)$.

### Lista de Adyacencia

Podemos representar un grafo con una **lista de adyacencia**, esto es, una lista que represente los nodos donde cada valor de esta lista sea una lista con los nodos entre los cuales existe una arista hacia el nodo indexado.

Pros:

* Podemos listar a los vecinos de un nodo en $O(vecinos)$.
* El espacio que utiliza en la memoria es $O(aristas)$.

Contras:

* Saber si dos nodos estan conectados es $O(vecinos)$.
* Lo mismo pasa al agregar o eliminar

## Arbol

Es un tipo de grafo que posee las siguientes caracteristicas:

* No tienen ciclos.
* Si se le quita una arista deja de ser conexo.
* Si se le agrega una ariste se crean ciclos.
* Existe solo un camino entre cada par de nodos.
* Si el grafo tiene $n$ nodos, tendra $n-1$ aristas.

## Breadth-first Search

Este algoritmo visita todos los nodos de un grafo desde un punto de partida, nodo, dado. Para realizar esto visita primero todos los nodos que se encuentran a una distancia de 1 de el, luego todos los nodos a una distancia 2 de el y asi hasta haber completado de recorrer todo el grafo. **La complejidad de este algoritmo es $O(n+m)$, donde $n$ es el numero de nodos del grafo y $m$ el numero de aristas, pues el algoritmo procesa cada nodo y arista una sola vez.**

Su implementacion es la siguiente:

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph; // Grafo en forma de lista de adyacencia
vector<int> dist; // Arreglo con las distancias desde el nodo de partida hacia los demas nodos
vector<int> parent; // Para guardad el padre de cada nodo (que utilidad?)

/*
Breadth First Search
s: nodo inicial
n: cantidad de nodos
*/
void bfs(int s, int n) {
    dist.assign(n, -1); parent.assign(n, -1);

    queue<int> Cola;
    dist[s] = 0;
    Cola.push(s);
    while (!Cola.empty()) {
        int u = Cola.front(); Cola.pop();

        for (int v: graph[u]) { // Por cada vecino de u
            if (dist[v] == -1) {  // veo si ya lo visite
                dist[v] = dist[u] + 1;  // guardo la distancia hasta v
                parent[v] = u;  // guardo al padre de v
                Cola.push(v);  // lo agrego a la cola
            }
        }
    }
}
```

**OBS: Este algoritmo no pasa por mas de una componente conexa (si es que hay mas de una).**

## Depth-first Search

Este algoritmo sigue un unico camino desde un nodo inicial siempre y cuando vaya encontrando nuevos nodos. En caso de no encontrar uno nuevo regresa al nodo previo y comienza a recorrer nuevos caminos. El camino a recorrer es escogido arbitrariamente. El algoritmo mantiene un seguimiento de los nodos visitados para asi procesar una unica vez cada nodo. **La complejidad de este algoritmo es $O(n+m)$, donde $n$ es el numero de nodos del grafo y $m$ el numero de aristas, pues el algoritmo procesa cada nodo y arista una sola vez.**

Para su implementacion existen dos versiones, una recursiva y otra iterativa:

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void dfs_recursive(int s, vector<vector<int>> &graph, vector<int> &visited) {
    if (visited[s] == 1) return; // Si ya esta visitado retornamos
    visited[s] = 1; // Marcamos que lo visitamos
    for (int u: graph[s]) { // Process
        dfs_recursive(u, grafo, visited);
    }
}

void dfs_iterativo(int s, vector<vector<int>> &graph, vector<int> &visited) {
    stack<int> Pila;
    Pila.push(s);  // Metemos a la pila el nodo inicial

    while (!Pila.empty()) {
        int u = Pila.top(); Pila.pop(); // Tomamos un nodo
        visited[u] = 1;  // lo marcamos como visitado

        for (int v: grado[u]) { // Para cada vecino del nodo
            if (visited[v] == 0) {  // vemos si lo visitamos
                visited[v] = 1;
                Pila.push(v);  // Lo metemos a la pila
            }
        }
    }
}
```
