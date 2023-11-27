#include<bits/stdc++.h>

using namespace std;

template<class T>
struct Hash{
	long long m; 	// Modulo, opciones: 1e9+7, 1e9+9, 1e9+123
	long long b; 	// Base, mayor que el número de elementos distintos. 
					// Algunos dicen que mayor al mayor valor de los elementos.
					// Opciones: 31, 127, 139
	std::vector<long long> pot, H;
	int n;
	Hash(T &s, long long b = 127, long long m = 1e9+123) : b(b), m(m), n(s.size()) {
		pot.resize(n + 1); H.resize(n + 1);
		H[n - 1] = s[n - 1];
		for (int i = n - 2; i >= 0; i --)
			H[i] = (s[i] + H[i + 1] * b) % m;
		pot[0] = 1;
		for (int i = 1; i <= n; i ++)
			pot[i] = (pot[i - 1] * b) % m;
	}
	// Calcula el hash del substring que parte en i de largo k.
	// k debería ser mayor a 0.
	long long hash(int i, int k){
		if (i + k <= n) 
			return (m + H[i] - (H[i + k] * pot[k] % m)) % m;
		return (hash(i, n - i) + hash(0, k - (n - i)) * pot[n - i]) % m;
	}
};

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	string s;
	cin >> s;
    int imd = s.size() + 1;
    Hash<string> RH(s);

    for (int i = 0; i < s.size()-1; i ++){
		if (RH.hash(0, i + 1) == RH.hash(s.size() - i - 1, i + 1)) {
			cout << (i+1) << " ";
		}
	}

	cout << "\n";

	return 0;
}