#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> &dist, vector<vector<int>> graph, vector<int> &parent, int target) {
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                if (v == target) return;
                q.push(v);
            }
        }
    }
}

int main() {
    int V, E; cin >> V >> E;
    vector<vector<int>> adj(V);
    vector<int> dist(V, -1), parent(V, -1);

    for (int i=0; i<E; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int end = V-1;
    bfs(0, dist, adj, parent, end);
    int d = dist[end];
    if (d == -1) cout << "IMPOSSIBLE" << '\n';
    else {
        cout << d+1 << '\n';
        int i = end;
        vector<int> path;
        while (i != 0) {
            path.push_back(i);
            i = parent[i];
        }
        path.push_back(0);
        reverse(path.begin(), path.end());
        for (int i=0; i<d+1; i++) {
            cout << path[i]+1 << " ";
        }
    }
    cout << '\n';
}