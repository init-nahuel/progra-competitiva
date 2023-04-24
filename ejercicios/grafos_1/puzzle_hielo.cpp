#include <bits/stdc++.h>

using namespace std;

void dfs_recursive(pair<int, int> p, vector<vector<int>> &graph, vector<vector<int>> &visited) {
    int x = p.first, y = p.second;
    if (visited[x][y] == 1) return;
    visited[x][y] = 1;
    for (int i=0; i<1000; i++){
        for (int j=0; j<1000; j++) {
            if (graph[x][j] == 1) dfs_recursive({x, j}, graph, visited);
        }
        if (graph[i][y] == 1) dfs_recursive({i, y}, graph, visited);
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> visited(1000, vector<int>(1000, 0));
    vector<vector<int>> graph(1000, vector<int>(1000, 0));
    vector<pair<int, int>> nodes;
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        graph[x][y] = 1;
        nodes.push_back({x, y});
    }

    int conx = 0;
    for (pair<int, int> p: nodes) {
        int x = p.first, y = p.second;
        if (visited[x][y] == 0) conx += 1;
        dfs_recursive(p, graph, visited);
    }

    int res = (conx != 1) ? conx - 1 : 0;
    cout << res << "\n";

    return 0;
}