#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> line, int size) {
    int max = 1; 
    for (int i=0; i<size-1; i++) {
        int val = line[i], next = line[i+1], j = i+1, pos_max = 0;
        while (val != next && j<size) {
            pos_max += 1; j++;
            next = line[j];
        }
        if (pos_max > max) max = pos_max;
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