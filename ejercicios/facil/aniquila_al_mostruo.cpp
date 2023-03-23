#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    long long hc, dc; cin >> hc >> dc;
    int hm, dm; cin >> hm >> dm;
    int k, w, a; cin >> k >> w >> a;
    double c_turns = ceil(hc/dm), m_turns = ceil(hm/dc);
    string res = "NO";
    
    if (c_turns >= m_turns) res = "YES";
    else {
        while (c_turns < m_turns) {
            for (int i=k; i>=0; i--) {
                for (int j=0;j<=k; j++) {
                    double new_hc = hc+j*a, new_dc = dc+i*w;
                    c_turns = ceil(new_hc/dm);
                    m_turns = ceil(hm/new_dc);
                }
                if (c_turns >= m_turns) {
                    res = "YES"; break;
                }
            }
            break;
        }
    }
    cout << res << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve(); 
    return 0;
}