#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n) {
    ll res = 0;
    for (int i=1; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            res += __gcd(i, j);
        }
    }

    return res;
}

int main() {
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        ll res = solve(n);
        cout << res << "\n";
    }
    return 0;
}