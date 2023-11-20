#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

struct segment_tree{

  int N;
  vector <ll> tree, arr;
  
  segment_tree(vector <ll> &A){
    // constructor
    N = A.size();
    arr = A;
    tree.resize(4*N);
    build(0, 0, N-1);
  }

  ll merge(ll a, ll b){
    return a+b;
  }

  void build(int n, int i, int j){
    if(i == j){
      tree[n] = arr[i];
      return;
    }
    int mid = (i+j)/2;
    build(2*n+1, i, mid);
    build(2*n+2, mid+1, j);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }

  // int query(int l, int r){
  //   return query(0, 0, N-1, l, r);
  // }

  // int query(int n, int i, int j, int l, int r){
  //   // nodo actual mira intervalo [i,j]
  //   // queremos responder consulta [l,r]
  //   // caso 1: contenido totalmente
  //   if(l <= i && j <= r){
  //     return tree[n];
  //   }
  //   // caso 2: [i,j] está fuera de [l,r]
  //   if(j < l || r < i){
  //     return 0;
  //   }
  //   // caso 3: contenido parcialmente
  //   int mid = (i+j)/2;
  //   return merge(query(2*n+1, i, mid, l, r),query(2*n+2, mid+1, j, l, r));
  // }

  ll update(int idx){
    return update(0, 0, N-1, idx);
  }

  ll update(int n, int i, int j, int idx){
    // no contiene a idx
    if(idx < i || idx > j){
      return 0;
    }
    if(i == j){
      ll val = tree[n];
      tree[n] = 0;
      return val;
    }
    int mid = (i+j)/2;
    ll val = update(2*n+1, i, mid, idx) + update(2*n+2, mid+1, j, idx);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    return val;
  }
};

int main() {
  fast;

  int n; cin >> n;
  vector<ll> nums(n);

  for (int i=0; i<n; i++) {
    cin >> nums[i];
  }

  segment_tree ST(nums);

  for (int i=0; i<n; i++) {
    int x; cin >> x;
    ll ans = ST.update(x-1);
    cout << ans << endl;
    print_array(ST.tree);
  }

  return 0;
}
