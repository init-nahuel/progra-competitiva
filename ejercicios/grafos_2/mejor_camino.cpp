#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll INF = 1e18;

vector <ll> dijkstra(vector<vector<pair<int, ll>>> adj, int size, int start, int end) {
    using state = pair<int, ll>;
    priority_queue <state, vector<state>, greater<state>> pq;
    vector<ll> dist(size, INF);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (weight != dist[u]) continue;

        for (auto [v, w]: adj[u]) {
            if (weight + w < dist[v]) {
                dist[v] = weight + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {

    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<vector<pair<int, ll>>> adj(n), reverse_adj(n);
        vector<tuple<int, int, ll>> edges(n);
        int s, d; cin >> s >> d;
        for (int i=0; i<m; i++) {
            int u, v, p; cin >> u >> v >> p;
            adj[u].push_back({v, p});
            reverse_adj[v].push_back({u, p});
            edges[i] = {u, v, p};
        }
        vector<ll> dijkstra_graph = dijkstra(adj, n, s, d);
        vector<ll> dijkstra_reverse_graph = dijkstra(reverse_adj, n, d, s);
        int short_distance = dijkstra_graph[d];

        for (auto [u, v, p]: edges) {
            if (dijkstra_graph[u] + p + dijkstra_reverse_graph[v] == short_distance) {
                adj[u].erase(find(adj[u].begin(), adj[u].end(), pair(v, p)));
            }
        }

        vector<ll> ans_dijkstra = dijkstra(adj, n, s, d);
        int ans = (ans_dijkstra[d] != INF) ? ans_dijkstra[d] : -1;
        cout << ans << "\n";
    }

    return 0;
}