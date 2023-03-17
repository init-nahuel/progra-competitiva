#include <iostream>
#include <vector>

using namespace std;

vector<int> to_bit(string w) {
    int n = w.length();
    vector<int> bit(n);
    for (int i=0; i<n; i++) {
        bit[i] = (w[i] == 'R') ? 1 : 0;
    }
    return bit;
}

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

vector<int> xor_op(vector<int> bit1, vector<int> bit2) {
    int n = max(bit1.size(), bit2.size());
    int m = min(bit1.size(), bit2.size());
    vector<int> res(n, 0);
    for (int i=0; i<m; i++) {
        res[i] = bit1[i] ^ bit2[i+m-1];
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    // Usar bitwise: Transformar los strings a bits que sean la representacion de este
    // R -> 1 y B -> 0, Ej: RBRB -> 1010
    // BRBB -> 0100,  RBR -> 101
    // OUTPUT: 0100 XOR _101 = _001 
    // BRBRR -> 01011,  BRBR -> 0101
    // OUTPUT: 01011 XOR 0101 = _1110
    // El XOR debe empezar el bit con 1, si empieza con 0 entonces la torre no es bellisima
    vector<int> bit_s = to_bit(s), bit_t = to_bit(t), bit_xor = xor_op(bit_s, bit_t);
    string res = (bit_xor[max(bit_s.size(), bit_t.size())-1] == 1) ? "YES" : "NO";
    cout << res << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}