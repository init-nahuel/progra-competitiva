#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> modified_sieve(int n) {
    vector<int> sieve(n+1, 0);
    vector<int> primes(n+1, 1);
    for (int i=2; i<=n; i++) {
        if (primes[i] && (ll) i*i <= n) {
            sieve[i] = sieve[i-1] + 1;
            for (int j= i*i; j<=n; j+=i) {
                primes[j] = 0;
            }
        } else {
            sieve[i] = sieve[i-1];
        }
    }

    return sieve;
}

pair<int, int> solve(long long n, long long k, vector<int> sieve) {
    int sqrt_n = (int) floor(sqrtl(n)), sqrt_k = (int) floor(sqrtl(k));
    int count_n = sieve[sqrt_n], count_k = sieve[sqrt_k];

    return make_pair(count_n*2, count_n-count_k);
}

int main() {
    int t; cin >> t;
    vector<int> sieve = modified_sieve(100000);
    while (t--) {
        ll n, k; cin >> n >> k;
        if (n < 4 || k > n) {
            cout << 0 << " " << 0 << "\n";
            continue;   
        }
        pair<int, int> ans = solve(n, k, sieve);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}