#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t; t++;
    vector<string> ans_vec;
    while (--t) {
        string ans = "";
        for (int i=0; i<8; i++) {
            string line; cin >> line;
            for (auto c: line) {
                if (c != '.') ans += c;
            }
        }
        ans_vec.push_back(ans);
    }
    for (auto ans: ans_vec) {
        cout << ans << "\n";
    }
    return 0;
}