#include<bits/stdc++.h>
using namespace std;

bool cmp(int n, pair<int, int>& p) {
    return p.first <= n;
}

int main() {
    int x, n; cin >> x >> n;
    set<pair<int, int>> sem;
    
    int s; cin >> s;
    sem.insert({s, x-s});
    int longest = x-s > s ? x-s : s;
    cout << longest << " \n";
    
    for (int i=0; i<n-1;i++) {
        cin >> s;
        auto si = lower_bound(sem.begin(), sem.end(), s, cmp);
        pair<int, int> pi = *si;
        pi.second = s - pi.first;
        int pos_longest = pi.second > 2*s - pi.first ? pi.second - s : s - pi.first;
        sem.insert({s, pi.second - s});
        longest = longest > pos_longest ? longest : pos_longest;
        cout << longest << "\n";
    }

    return 0;
}