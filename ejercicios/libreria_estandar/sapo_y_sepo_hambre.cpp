#include <iostream>
#include <vector>
#include <algorithm>

// TLE: IMPROVE SOLUTION

using namespace std;

int solve(vector<int> line, int size) {
    int max = 1;
    for (int i=0; i<size; i++) {
        vector<int> sub_array = {line[i]};
        int poss_max = 0;

        for (int j=i+1; j<size; j++) {
            int val = line[j];
            if (find(sub_array.begin(), sub_array.end(), val) != sub_array.end()) break;
            sub_array.push_back(val);
        }

        poss_max = sub_array.size();
        if (poss_max > max) max = poss_max;
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