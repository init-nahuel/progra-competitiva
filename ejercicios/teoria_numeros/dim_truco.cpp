#include<bits/stdc++.h>
using namespace std;

vector<int> modified_sieve(int n) {
    vector<int> sieve(n, 0);
    int counter = 0;
    for (int i=2; i<n; i++) {
        if (sieve[i]) continue;
        int div_3 = i*i;
        if (div_3 >= n) break;
        sieve[div_3] = 1;
    }

    return sieve;
}

pair<int, int> solve(int n, int k) {
    vector<int> sieve = modified_sieve(n);
    
    return make_pair(count(sieve.begin(), sieve.end(), 1), count(sieve.begin() + k + 1, sieve.end(), 1));
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (n < 4 || k > n) {
            cout << 0 << 0 << "\n";
            continue;
        }
        pair<int, int> ans = solve(n, k);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}