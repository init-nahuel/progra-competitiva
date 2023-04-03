#include <iostream>
#include <vector>
#include <set>

// Careful: you must use std::set::lower_bound method in sets due to it's Binary Search Tree implementation
// Useful info: https://www.geeksforgeeks.org/difference-between-stdsetlower_bound-and-stdlower_bound-in-c/

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a, b, c;
    multiset<int> multiset_b;
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        a.push_back(v);
    }
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        b.push_back(v);
        multiset_b.insert(v);
    }

    for (int i=0; i<n; i++) {
        int desired_val = n - a[i];
        auto it = multiset_b.lower_bound(desired_val);
        if (it != multiset_b.end()) {
            int val = (*it+a[i])%n;
            c.push_back(val); multiset_b.erase(it);
        }
        else {
            auto min_it = multiset_b.begin(); int val = (*min_it+a[i])%n;
            c.push_back(val); multiset_b.erase(min_it); 
        }
    }

    for (int i=0; i<n; i++) {
        cout << c[i] << ' ';
    }
    cout << '\n';
    return 0;
}