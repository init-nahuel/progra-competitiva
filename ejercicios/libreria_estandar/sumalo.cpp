#include <bits/stdc++.h>
using namespace std;

bool cmp(int n, pair<int, int>& p) {
    return p.first > n;
}

int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> arr;

    for (int i=0; i<n; i++) {
        int val; cin >> val;
        arr.push_back({val, i+1});
    }

    sort(arr.begin(), arr.end());
    auto l = arr.begin();
    auto r = upper_bound(arr.begin(), arr.end(), x, cmp) == arr.end() ? arr.end() - 1 : upper_bound(arr.begin(), arr.end(), x, cmp);

    while (l < r) {
        pair<int, int> pl = *l, pr = *r;
        if (pl.first + pr.first == x) {
            cout << pl.second << " " << pr.second << "\n";
            goto end;
        }
        else if (pl.first + pr.first > x) {
            r--;
        }
        else if (pl.first + pr.first < x) {
            l++;
        }
    }

    cout << "IMPOSSIBLE\n";

    end:
        return 0;
}