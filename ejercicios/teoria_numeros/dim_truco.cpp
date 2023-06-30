#include<bits/stdc++.h>
using namespace std;

vector<int> modified_sieve(int n) {
    vector<int> sieve(n+1, 0);
    vector<int> squares_prime;
    for (int i=2; i<=n; i++) {
        if (sieve[i]) continue;
        for (int j=i*2; j<=n; j+=i) {
            if (j == i*i) {
                sieve[j] = i*i;
                squares_prime.push_back(i*i);
                continue;
            }
            sieve[j] = i;
        }
    }

    return squares_prime;
}

pair<int, int> solve(int n, int k, vector<int> sieve) {
    int sqrt_n = (int) floor(sqrt(n)), sqrt_k = (int) floor(sqrt(k));
    auto divs_minor_n = lower_bound(sieve.begin(), sieve.end(), n, less_equal<int>());
    auto divs_great_k = lower_bound(sieve.begin(), sieve.end(), k, less_equal<int>());

    return make_pair(divs_minor_n - sieve.begin(), divs_minor_n - divs_great_k);
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