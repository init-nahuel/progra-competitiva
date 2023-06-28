#include<bits/stdc++.h>
using namespace std;

vector<int> modified_sieve(int n) {
    vector<int> sieve(n, 0);
    int counter = 0;
    for (int i=2; i<n; i++) {
        if (sieve[i]) continue;
        counter += 1;
        for (int j=2*i; j<n; j+=i) {
            sieve[j] = counter;
        }
    }

    return sieve;
}

pair<int, int> solve(int n, int k) {
    vector<int> sieve = modified_sieve(n);
    
    return make_pair(sieve[n-1], sieve[k+1]);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (n < 4) {
            cout << 0 << 0 << "\n";
            continue;
        }
        pair<int, int> ans = solve(n, k);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}