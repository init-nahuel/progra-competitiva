#include<bits/stdc++.h>
using namespace std;

set<int> modified_sieve(int n) {
    vector<int> sieve(n, 0);
    set<int> divs_3;
    int counter = 0;
    for (int i=2; i<n; i++) {
        if (sieve[i]) continue;
        divs_3.insert(i*i);
        for (int j=i; j<n; j+=i) {
            sieve[j] = j;
        }
    }

    return divs_3;
}

pair<int, int> solve(int n, int k, set<int> sieve) {
    int len_sieve = size(sieve);
    auto it_n = sieve.lower_bound(n);
    auto it_k = sieve.lower_bound(k);
    int divs_3 = distance(sieve.begin(), it_n);
    int great_k = distance(it_k, sieve.end());
    return make_pair(divs_3, great_k);
}

int main() {
    int t; cin >> t;
    set<int> sieve = modified_sieve(100000);
    while (t--) {
        int n, k; cin >> n >> k;
        if (n < 4 || k > n) {
            cout << 0 << 0 << "\n";
            continue;   
        }
        pair<int, int> ans = solve(n, k, sieve);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}