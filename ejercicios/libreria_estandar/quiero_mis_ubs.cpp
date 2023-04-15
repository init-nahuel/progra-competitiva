#include <iostream>
#include <vector>

// TLE: IMPROVE SOLUTION

using namespace std;

vector<pair<string, string>> lexicographical_transform(vector<pair<string, string>> *pair_deps, int size) {
    for (int i=0; i<size; i++) {
        string str1 = (*pair_deps)[i].first, str2 = (*pair_deps)[i].second;
        if (str2.compare(str1) < 0) {
            pair<string, string> p = {str2, str1}; (*pair_deps)[i] = p;
        }
    }
    return *pair_deps;
}

int friends(string str1, string str2, vector<pair<string, string>> pair_deps, int size) {
    for (int i=0; i<size; i++) {
        pair<string, string> p = pair_deps[i];
        if (p.first == str1 && p.second == str2) return 1;
    }
    return 0;
}

vector<string> solve(int s, int l, int n, vector<pair<string, string>> pair_deps, vector<string> *auxs_line) {
    pair_deps = lexicographical_transform(&pair_deps, l);
    for (int i=n-2; i>=0; i--) {
        string str1 = (*auxs_line)[i], str2 = (*auxs_line)[i+1];
        int j = i;
        while (friends(str2, str1, pair_deps, l) && j>=0) {
            (*auxs_line)[j] = str2; (*auxs_line)[j+1] = str1;
            str1 = (*auxs_line)[j-1], str2 = (*auxs_line)[j];
            j--;
        }
    }
    return *auxs_line;
}

int main() {
    // s: num de departamentos, l: num de pares que se llevan bien, n: num de auxs en fila
    int s, l, n; cin >> s >> l >> n;
    vector<string> deps;
    vector<pair<string, string>> pair_deps;
    vector<string> auxs_line;
    for (int i=0; i<s; i++) {
        string dep; cin >> dep;
        deps.push_back(dep);
    }
    for (int i=0; i<l; i++) {
        pair<string, string> p; cin >> p.first >> p.second;
        pair_deps.push_back(p);
    }
    for (int i=0; i<n; i++) {
        string aux; cin >> aux;
        auxs_line.push_back(aux);
    }

    if (l == 0) for (int i=0; i<n; i++) {
        cout << auxs_line[i] << " ";
    }
    else if (s==1 || n==1) for (int i=0; i<n; i++) cout << auxs_line[i] << "\n"; // TA MALO EN CASO DE QUE SEA L = 0
    else {
        vector<string> new_line = solve(s, l, n, pair_deps, &auxs_line);
        for (int i=0; i<n; i++) {
            cout << new_line[i] << " ";
        }
        cout << "\n";
    }
    cout << '\n';

    return 0;
}