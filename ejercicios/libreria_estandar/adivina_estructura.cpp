#include <bits/stdc++.h>

using namespace std;

// Returns 1 if the structure is a stack and 0 otherwise.
int is_a_stack(vector<pair<int, int>> v, int size) {
    stack<int> s;
    for (int i=0; i<size; i++) {
        pair<int, int> p = v[i];
        if (p.first == 1) {
            s.push(p.second);
        }
        else {
            if (s.empty()) return 0;
            int value = s.top(); s.pop();
            if (value != p.second) return 0;
        }
    }
    
    return 1;
}

// Returns 1 if the structure is a queue and 0 otherwise.
int is_a_queue(vector<pair<int, int>> v, int size) {
    queue<int> q;
    for (int i=0; i<size; i++) {
        pair<int, int> p = v[i];
        if (p.first == 1) {
            q.push(p.second);
        }
        else {
            if (q.empty()) return 0;
            int value = q.front(); q.pop();
            if (value != p.second) return 0;
        }

    }

    return 1;
}

// Returns 1 if the structure is a priority queue and 0 otherwise
int is_a_prior_queue(vector<pair<int, int>> v, int size) {
    priority_queue<int> pq;
    for (int i=0; i<size; i++) {
        pair<int, int> p = v[i];
        if (p.first == 1) {
            pq.push(p.second);
        }
        else {
            if (pq.empty()) return 0;
            int value = pq.top(); pq.pop();
            if (value != p.second) return 0; 
        }
    }

    return 1;
}

int main() {
    vector<string> poss_struct = {"stack", "queue", "priority queue", "impossible", "not sure"};
    int n;
    while(cin >> n){ // terminará cuando llegue al EOF
        // procesar caso de prueba
        if (to_string(n) == "EOF") break;

        vector<pair<int, int>> ops;
        for (int i=0; i<n; i++) {
            pair<int, int> p; cin >> p.first >> p.second;
            ops.push_back(p);
        }
        
        if (is_a_stack(ops, n) && !is_a_queue(ops, n) && !is_a_prior_queue(ops, n)) cout << "stack\n";
        else if (!is_a_stack(ops, n) && is_a_queue(ops, n) && !is_a_prior_queue(ops, n)) cout << "queue\n";
        else if (!is_a_stack(ops, n) && !is_a_queue(ops, n) && is_a_prior_queue(ops, n)) cout << "priority queue\n";
        else if (is_a_stack(ops, n) || is_a_queue(ops, n) || is_a_prior_queue(ops, n)) cout << "not sure\n";
        else cout << "impossible\n";

        ops.clear();
    }
    return 0;
}