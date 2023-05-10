#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct DSU {
    vector<int> rep, sz;
    DSU(int n) {
        rep.resize(n); sz.resize(n);
        for (int i=0; i<n; i++) {
            rep[i] = i; sz[i] = 1;
        }
    }
    int find_set(int v) {
        if (v == rep[v]) return v;
        return rep[v] = find_set(rep[v]);
    }
    void union_set(int a, int b) {
        int repa = find_set(a), repb = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            rep[b] = a;
            sz[a] += sz[b];
        }
    }
};

ll kruskal(int n, vector<tuple<ll, int, int>> &edges) {
    vector<bool> rel(n, false);
    DSU dsu(n);
    sort(edges.begin(), edges.end());
    ll ans = 0;
    // rel[get<1>(edges[0])] = false; // marcamos el nodo con menor peso como el supervisor
    for(auto [w, u, v]: edges) {
        if (dsu.find_set(u) != dsu.find_set(v) && rel[v] == false) {
            rel[v] = true;
            ans += w;
            dsu.union_set(u, v);
        }
    }
    if (count(rel.begin(), rel.end(), false) != 1) ans = -1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int q; cin >> q;
    }
    int m; cin >> m;
    vector<tuple<ll, int,  int>> edges(m);
    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {c, a-1, b-1};
    }
    cout << kruskal(n, edges) << "\n";
    return 0;
}