#include <iostream>
#include <vector>

using namespace std;

int is_beautiful(string w) {
    int n = w.length();
    if (n == 1) return 1;
    char prev = w[0];
    for (int i=1; i<n; i++) {
        if (prev == w[i]) return 0;
        prev = w[i];
    }
    return 1;
}

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    string res = "NO";
    if (is_beautiful(s) && is_beautiful(t)) {
        res = "YES";
    }
    else if (!is_beautiful(s) && is_beautiful(t)) {
        while(n>1) {
            t.push_back(s[n-1]);
            s.pop_back(); n--;
            if (is_beautiful(s) && is_beautiful(t)) {
                res = "YES"; break;
            }
        }
    }
    else if (is_beautiful(s) && !is_beautiful(t)) {
        while (m>1) {
            s.push_back(t[m-1]);
            t.pop_back(); m--;
            if (is_beautiful(s) && is_beautiful(t)) {
                res = "YES"; break;
            }
        }
    }

    cout << res << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}