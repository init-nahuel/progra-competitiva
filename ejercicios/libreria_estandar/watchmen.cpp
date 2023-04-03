#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    int count = 0;
    ll ans = 0;
    map<ll, ll> x_coord, y_coord;
    map<pair<ll, ll>, ll> coords;

    for (int i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        pair<ll, ll> p = {x, y};
        x_coord[x]++, y_coord[y]++; coords[p]++;
        
    }

    for (auto [llave, valor]: x_coord) {
        ans += (valor*(valor-1))/2;
    }
    for (auto [llave, valor]: y_coord) {
        ans += (valor*(valor-1))/2;
    }
    for (auto [llave, valor]: coords) {
        if (valor > 1) ans -= (valor*(valor-1))/2;
    }

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}