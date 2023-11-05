#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

struct segment_tree{

  int N;
  vector <bitset<26>> tree;
  
  segment_tree(string &A){
    // constructor
    N = A.size();
    tree.resize(4*N);
    build(0, 0, N-1, A);
  }

  bitset<26> merge(bitset<26> a, bitset<26> b){
    // set<char> res;
    // set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(res, res.begin()));
    // a.insert(b.begin(), b.end());
    return a | b;
  }

  void build(int n, int i, int j, string &A){
    // n: indice del nodo
    // nodo mira segmento [i,j]
    if(i == j){
      tree[n][A[i]-'a'] = 1;
      return;
    }
    int mid = (i+j)/2;
    // hijo izq: 2n+1
    // hijo der: 2n+2
    build(2*n+1, i, mid, A);
    build(2*n+2, mid+1, j, A);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }

  int query(int l, int r){
    return query(0, 0, N-1, l, r).count();
  }

  bitset<26> query(int n, int i, int j, int l, int r){
    // nodo actual mira intervalo [i,j]
    // queremos responder consulta [l,r]
    // caso 1: contenido totalmente
    if(l <= i && j <= r){
      return tree[n];
    }
    // caso 2: [i,j] está fuera de [l,r]
    if(j < l || r < i){
      return bitset<26>();
    }
    // caso 3: contenido parcialmente
    int mid = (i+j)/2;
    return merge(query(2*n+1, i, mid, l, r),query(2*n+2, mid+1, j, l, r));
  }

  void update(int idx, char x){
    // A[idx] = x
    bitset<26> b;
    b[x-'a'] = 1;
    update(0, 0, N-1, idx, b);
  }

  void update(int n, int i, int j, int idx, bitset<26> x){
    // no contiene a idx
    if(idx < i || idx > j){
      return;
    }
    if(i == j){
      tree[n] = x;
      return;
    }
    int mid = (i+j)/2;
    update(2*n+1, i, mid, idx, x);
    update(2*n+2, mid+1, j, idx, x);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }
};

int main() {
  fast;

  string s; cin >> s;

  segment_tree ST(s);

  int q; cin >> q;

  for (int i=0; i<q; i++) {
      int t;
      cin >> t;
      if (t == 1) {
        int a; char b; cin >> a >> b;
        ST.update(a-1, b);
      } else {
        int a, b; cin >> a >> b;
        int ans = ST.query(a-1, b-1);
        cout << ans << endl;
      }
  }

  return 0;
}