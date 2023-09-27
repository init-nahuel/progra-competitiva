#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b, c; cin >> n >> a >> b >> c;
    long long ans = 0;

    for (int i=0; i<=4000; i++) {
        for (int j=0; j<=4000; j++) {
            long long k = (n - a*i - b*j)/c;
            if (a*i+b*j+c*k == n && k >= 0) {
                ans = max(ans, (long long) i+j+k);
            }
        }
    }

    cout << ans << endl;

    return 0;
}