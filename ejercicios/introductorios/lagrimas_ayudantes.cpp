#include<bits/stdc++.h>
using namespace std;

int main() {
    string vars; cin >> vars;
    vector<int> alphabet(26, 0);
    string is_ofuscated = "YES\n";
    if (vars[0] != 'a') is_ofuscated = "NO\n";
    else {
        alphabet[0] = 1; 
        for (int i=1; i<size(vars); i++) {
            char c = vars[i];
            if (alphabet[c - 'a' - 1] != 1 && c != 'a') {
                is_ofuscated = "NO\n";
                break;
            }
            alphabet[c-'a'] = 1;
        }
    }
    cout << is_ofuscated;
    return 0;
}