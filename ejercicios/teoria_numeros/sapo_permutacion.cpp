#include <bits/stdc++.h>

using namespace std;

int solve(set<int> permutation) {
    int j = *permutation.begin();
    int max_k = j;
    permutation.erase(j);
    for (int i : permutation) {
        max_k = __gcd(max_k,i);
        j = i;
    }

    return max_k;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> gcd_vals;
        vector<int> permutation(n);
        for (int i=0; i<n; i++) {
            int p; cin >> p;
            permutation[i] = p;
            gcd_vals.insert(abs(p-i-1)); 
        }
        int ans = solve(gcd_vals);
        cout << ans << '\n';
    }

    return 0;
}