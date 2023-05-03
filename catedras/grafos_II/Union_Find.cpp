#include <bits/stdc++.h>
using namespace std;

// Union-Find también es conocido como DSU (Disjoint Set Union)
struct DSU{ //Disjoint Set Union
    // Casi O(1) amortizado
    vector <int> parent, sz; // sz = size
    DSU(int n){
        parent.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(sz[a] < sz[b])
                swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// ejemplo de uso:
	int n = 10;
	DSU dsu(n); // creamos nuestro dsu con n nodos
	dsu.union_set(0, 1);
	dsu.union_set(1, 2);
	dsu.union_set(2, 3);
	dsu.union_set(3, 4);
	if(dsu.find_set(0) == dsu.find_set(4)){
		cout << "Funciona :)\n";
	}
	// Más ejemplo de uso en el Algoritmo de Kruskal
	return 0;
}
