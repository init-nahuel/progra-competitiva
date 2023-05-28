#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

ld get_min_energy(multiset<ld> m, multiset<ld> d, int size) {
    ld energy = 0;
    
    for (int i=0; i<size; i++) {
        auto it_miner = m.begin();
        auto it_diamond = d.begin();
        
        ld miner = *it_miner, diamond = *it_diamond;
        energy += sqrtl(miner*miner + diamond*diamond);

        m.erase(it_miner); d.erase(it_diamond);
    }

    return energy;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        multiset<ld> diamonds, miner;
        for (int i=0; i<2*n; i++) {
            ld x, y; cin >> x >> y;
            if (x == 0) {
                miner.insert(y);
            }
            else {
                diamonds.insert(x);
            }
        }
        ld min_energy = get_min_energy(miner, diamonds, n);
        cout << fixed << setprecision(9) << min_energy << "\n";
    }

    return 0;
}