#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll INF = 1e18;

int main() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    using state = pair<ll, int>;
    priority_queue<state, vector<state>, greater<state>> pq;
    vector<ll> dist(n, INF);
    vector<int> parent(n, -1);

    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        auto [peso_camino, u] = pq.top();
        pq.pop();

        if (u == n-1) break; // Si llegamos al nodo final entonces existe camino

        if (peso_camino != dist[u]) continue;
    
        for (auto [v, w] : adj[u]) {
            if (peso_camino + w < dist[v]) {
                dist[v] = peso_camino + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    if (dist[n-1] == INF) cout << "-1\n";
    else {
        vector<int> path;
        int node = n-1;
        while (node != 0) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(0);
        for (int i=size(path)-1; i>=0; i--) {
            cout << path[i]+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}