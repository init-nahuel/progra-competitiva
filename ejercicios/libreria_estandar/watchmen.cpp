#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n; cin >> n;
    int count = 0;
    // map<pair<int, int>, int> x_coord, y_coord;
    map<pair<int, int>, int> map_points;

    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        pair<int, int> p1 = {x, 0}, p2 = {0, y};

        if (map_points.find(p1) == map_points.end()) map_points[p1] = 0;
        else map_points[p1] += 1;

        if (map_points.find(p2) == map_points.end()) map_points[p2] = 0;
        else map_points[p2] += 1;

        // if (x_coord.find(x) == x_coord.end()) x_coord[x] = 0;
        // else x_coord[x] +=1;

        // if (y_coord.find(y) == y_coord.end()) y_coord[y] = 0;
        // else y_coord[y] +=1;
    }

    for (auto it = map_points.begin(); it != map_points.end(); it++) count += it->second;
    // for (auto it = x_coord.begin(); it != x_coord.end(); it++) count += it->second;
    // for (auto it = y_coord.begin(); it != y_coord.end(); it++) count += it->second;
    cout << count << '\n';
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}