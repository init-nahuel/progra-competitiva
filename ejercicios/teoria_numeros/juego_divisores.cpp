#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll modular_exp(int base, int exp) {
    if (exp == 0) return 1;
    ll ans = modular_exp(base, exp/2);
    if (exp%2 == 1) return ((ans * ans)% mod * base) % mod;
    else return (ans * ans) % mod;
}

ll divisors_sum(ll n) {
    ll ans = 0;

    for (ll i=1; i<=n; i++) {}

    return ans;
}

int main() {
    ll n; cin >> n;
    ll b = 10e9 + 7;
    ll ans = divisors_sum(n);
    cout << ans << "\n";
}