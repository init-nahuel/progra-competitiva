#include <iostream>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int ancho_vereda = 0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a <= h) {
            ancho_vereda += 1;
        }
        else {
            ancho_vereda += 2;
        }
    }
    cout << ancho_vereda << endl;
    return 0;
}