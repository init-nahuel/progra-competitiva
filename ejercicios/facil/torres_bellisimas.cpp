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

vector<int> xor_op(vector<int> bit1, vector<int> bit2) {
    int n = bit1.size(), m = bit2.size(), min = (n<m) ? n : m;
    vector<int> res(min, 0); // Se puede hacer con el minimo tmbn
    if (n>m) {
        for (int i=0; i<m; i++) {
            res[i] = bit1[i+m-1] ^ bit2[i];
        }
    }
    else {
        for (int i=0; i<n; i++) {
            res[i] = bit1[i] ^ bit2[i+n-1];
        }

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
    string res = (bit_xor[min(bit_s.size(), bit_t.size())-1] == 1) ? "NO" : "YES";
    cout << res << "\n";
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

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    string res = "NO";
    while (n>0 && m>0) {
        if (is_beautiful(s) && is_beautiful(t)) {
            res = "YES"; break;
        }
        else if (!is_beautiful(s) && !is_beautiful(t)) break;
        else if (!is_beautiful(s) && is_beautiful(t)) {
            // TODO: Completar :D
        }
    }
    cout << res << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}