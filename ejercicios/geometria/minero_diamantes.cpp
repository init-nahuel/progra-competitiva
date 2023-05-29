#include <bits/stdc++.h>

using namespace std;

long double get_min_energy(vector<long long> m, vector<long long> d, int size) {
    long double energy = 0;

    for (int i=0; i<size; i++) {
        long long miner = m[i], diamond = d[i];
        energy += sqrtl(pow(miner, 2) + pow(diamond, 2));
    }

    return energy;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> diamonds, miner;
        for (int i=0; i<2*n; i++) {
            long long x, y; cin >> x >> y;
            if (x == 0) {
                miner.push_back(abs(y));
            }
            else {
                diamonds.push_back(abs(x));
            }
        }
        sort(diamonds.begin(), diamonds.end()); sort(miner.begin(), miner.end());
        long double min_energy = get_min_energy(miner, diamonds, n);
        cout << fixed << setprecision(11) << min_energy << "\n";
    }

    return 0;
}