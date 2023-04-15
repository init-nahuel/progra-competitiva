#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> line, int size) {
    int max = 0;
    int j = 0;
    int candidate_max = 0;
    multiset<int> my_set;
    for (int i=0; i<size; i++) {
        if (my_set.find(line[i]) == my_set.end()) {
            candidate_max += 1;
            my_set.insert(line[i]);
        }
        else {
            my_set.insert(line[i]);
            candidate_max += 1;
            while (j<i) {
                my_set.erase(my_set.find(line[j]));
                candidate_max -= 1;
                if (my_set.find(line[j]) == my_set.end()) break;
                j++;
            }
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