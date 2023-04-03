#include <bits/stdc++.h>

// TLE: Improve solution

using namespace std;

int solve(vector<int> line, int size) {
    int max = 0;
    for (int i=0; i<size; i++) {
        set<int> my_set;
        int j = i;
        int candidate_max = 0;
        while (j<size) {
            int v = line[j];
            if (my_set.count(v) == 0) {
                my_set.insert(v); candidate_max += 1;
            }
            else break;
            j++;
        }
        if (candidate_max > max) max = candidate_max;
    }
    return max;
}

int main() {
    int n; cin >> n;
    vector<int> line;
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        line.push_back(v);
    }
    
    if (n == 1) cout << 1 << '\n';
    else cout << solve(line, n) << '\n';

    return 0;
}