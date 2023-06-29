#include<bits/stdc++.h>
using namespace std;

vector<int> modified_sieve(int n) {
    vector<int> sieve(n+1, 0);
    int counter = 0;
    for (int i=2; i<=n; i++) {
        if (sieve[i]) continue;
        counter +=  1;
        for (int j=i*2; j<=n; j+=i) {
            if (j >= i*i) {
                sieve[j] = counter;
                continue;
            }
            sieve[j] = i;
        }
    }

    return sieve;
}

pair<int, int> solve(int n, int k, vector<int> &sieve) {
    int sqrt_n = (int) floor(sqrt(n)), sqrt_k = (int) floor(sqrt(k));
    int divs_3 = sieve[sqrt_n*sqrt_n];
    int divs_great_k = divs_3 - sieve[sqrt_k*sqrt_k];
    
    return make_pair(divs_3, divs_great_k);
}

int main() {
    int t; cin >> t;
    vector<int> sieve = modified_sieve((int) 10e5);
    while (t--) {
        int n, k; cin >> n >> k;
        if (n < 4 || k > n) {
            cout << 0 << " " << 0 << "\n";
            continue;   
        }
        pair<int, int> ans = solve(n, k, sieve);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}