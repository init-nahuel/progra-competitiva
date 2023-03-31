#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n; cin >> n;
    int count = 0;
    map<int, int> x_coord, y_coord;

    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;

        if (x_coord.find(x) == x_coord.end()) x_coord[x] = 0;
        else x_coord[x] +=1;

        if (y_coord.find(y) == y_coord.end()) y_coord[y] = 0;
        else y_coord[y] +=1;
    }

    for (auto it = x_coord.begin(); it != x_coord.end(); it++) count += it->second;
    for (auto it = y_coord.begin(); it != y_coord.end(); it++) count += it->second;
    cout << count << '\n';
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}