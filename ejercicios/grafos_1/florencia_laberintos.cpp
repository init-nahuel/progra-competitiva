#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector <vector <char>> grilla(n, vector<char>(m));
	// ... leemos la grilla desde la entrada estándar
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			char v; cin >> v;
			grilla[i][j] = v;
		}
	}
	vector <int> dx = {1, 0, -1, 0};
	vector <int> dy = {0, 1, 0, -1};
	// dx y dy indican los cuatro movimientos posibles. Un vector de movimiento sería (dx[i], dy[i])
	queue <pair<int,int>> q; // Nuestros nodos ahora son pares (x, y)
	vector <vector <int>> dist(n, vector <int>(m,-1)); // ahora nuestro vector dist es una matriz de nxm
	q.push({0,0}); // empezaremos desde el (0,0)
	while(!q.empty()){
		auto [x,y] = q.front();
		q.pop();
		for(int dir=0; dir<4; dir++){
			int nx = x+dx[dir];
			int ny = y+dy[dir];
			if(nx > n || ny > m || nx < 0 || ny <0) continue;/* coordenada (nx, ny) está fuera de la grilla */
			if(grilla[nx][ny] == '#') continue; /* hay una muralla, un obstáculo, un nodo que no queremos visitar, etc en (nx, ny) */
			if(dist[nx][ny] != -1) continue; // ya fue visitado
			dist[nx][ny] = dist[x][y]+1;
			q.push({nx,ny});
		}
	}
	// la respuesta queda guardada en dist
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << dist[i][j];
		}
		cout << "\n";
	}

}
