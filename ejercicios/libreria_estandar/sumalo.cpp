#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    int first = 0, second = 0;
    int pos_first = 0, pos_second = 0;
    for (int i=0; i<n; i++) {
        if (first+second == x) {
            cout << pos_first << " " << pos_second << "\n";
        } 
        int val; cin >> val;
        arr[i] = val;
        second = val
        pos_first = val;

    }

    return 0;
}