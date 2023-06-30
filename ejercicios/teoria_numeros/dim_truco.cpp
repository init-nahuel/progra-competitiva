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
    // int divs_3 = sieve[sqrt_n*sqrt_n];
    // int divs_great_k = divs_3 - sieve[sqrt_k*sqrt_k];
    int len = size(sieve);
    int bin_n = binary_search(sieve, sqrt_n, 0, n);
    int bin_k = binary_search(sieve, sqrt_k, 0, n);
    
    return make_pair(n - bin_n, bin_n - bin_k);
}

int binary_search(vector<int> arr, int val, int l, int r) {
    while (l <= r) {
        int mid = (l+r)/2;
        if (l == r) {
            return l;
        }
        if (arr[mid] > val) {
            r = mid;
        }
        else if (arr[mid] == val) {
            return mid;
        }
        else {
            l = mid;
        }
    }
    return l;
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