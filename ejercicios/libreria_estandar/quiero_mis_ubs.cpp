#include <iostream>
#include <vector>

using namespace std;

/*
Una forma interesante es ordenar lexicograficamente los pares de departamentos
pasados por el input, luego a la hora de trabajar con el string que representa la fila
bastara con una pasada directa sin tener que ver si cambiar el segundo por el primero
o tener el problema de agarrar un aux y tener que ver el primer y segundo elemento de la pair/tuple,
pues si no se encuentra en el primer elemento lo descartamos, notar que esto conlleva igual a ver ambos elementos,
sin embargo primero comparamos lexicograficamente ambos en la fila (aun cuando pueden no estar en los que se llevan bien)
y luego bastaria con ver si ese par se encuentra en esta lista (tomando el menor lex y el restante como segundo elemento 
de la tupla)
*/

void solve() {
    // s: num de departamentos, l: num de pares que se llevan bien, n: num de aux en fila
    int s, l, n; cin >> s >> l >> n;
    vector<string> deps;
    vector<string> pair_deps;
    for (int i=0; i<n ;i++) {
        string dep; cin >> dep;
        deps.push_back(dep);
    }
    for (int i=0; i<l; i++) {
        pair<string, string> pair;
        cin >> pair.first >> pair.second;
    }
}

int main() {
    // solve();
    string s;
    cin >> s; cout << s << endl;
    return 0;
}