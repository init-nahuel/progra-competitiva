#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        priority_queue<int> pq;
        long long squad_power = 0;
        for (int i=0; i<n; i++) {
            int s; cin >> s;
            if (s != 0) {
                pq.push(s);
            } else if (s == 0 && !pq.empty()) {
                squad_power += pq.top();
                pq.pop();
            }
        }
        cout << squad_power << "\n";
    }

    return 0;
}