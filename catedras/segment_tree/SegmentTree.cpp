#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct SegmentTree {
    int N;
    vector<ll> tree;
    const ll neutro = 1e18;

    SegmentTree(vector<ll> &A) {
        N = A.size();
        tree.resize(4*N);
        build(0, 0, N-1, A);
    }

    ll merge(ll a, ll b) {
        return min(a, b);
    }

    void build(int n, int i, int j, vector<ll> &A) {
        // n: la id del nodo actual
        // i, j: el intervalo que representa el nodo actual
        // A: el vector de inicializacion

        if (i==j) {
            tree[n] = A[i];
            return;
        }

        int mid = (i+j)/2;
        // hijo izq: 2n+1
        // hijo der: 2n+2
        build(2*n+1, i, mid, A);
        build(2*n+2, mid+1, j, A);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }

    ll query(int l, int r) {
        return query(0, 0, N-1, l, r);
    }

    ll query(int n, int i, int j, int l, int r) {
        // n, i, j: igual que en build
        // l, r: el intervalo que representa la query

        if (l <= i && j <= r) { // Caso completamente contenido
            return tree[n];
        }
        if (r < i || j < l) { // Caso afuera
            return neutro;
        }
        int mid=(i+j)/2;
        return merge(
            query(2*n+1, i, mid, l, r),
            query(2*n+2, mid+1, j, l, r));
    }

    void update(int t, ll val) {
        // Actualizamos el indice t con el valor val
        update(0, 0, N-1, t, val);
    }

    void update(int n, int i, int j, int t, ll val) {
        if (t < i || t > j) {
            return;
        }
        if (i == j) {
            tree[N] = val;
            return;
        }
        int mid = (i+j)/2;
        update(2*n+1, i, mid, t, val);
        update(2*n+2, mid+1, j, t, val);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }
};