#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> v;
    int ans = 1;
    int counter = 1;
    int prev = 0;
    int actual = 0;
    cin >> prev;
    for (int i=1; i<n; i++) {
        cin >> actual;
        if (actual - prev <= x){
            counter++;
        } else {
            ans = max(ans, counter);
            counter = 1;
        }
        prev = actual;
    }

    ans = max(ans, counter);
    cout << ans << endl;
    return 0;
}