#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>> cell, int i, int j, vector<vector<int>> dp) {
    
    if (cell[i][j] == '*' || cell[0][0] == '*') {
        return 0;
    } else {
        dp[0][0] = 1;
    }

    for (int i_cell=0; i_cell<=i; i_cell++) {
        for (int j_cell=0; j_cell<=j; j_cell++) {
            if (cell[i_cell][j_cell] == '*') {
                dp[i_cell][j_cell] = 0;
            } else {
                if (i_cell == 0 && j_cell == 0) {
                    continue;
                } else if (i_cell == 0 && j_cell != 0) {
                    dp[i_cell][j_cell] = dp[i_cell][j_cell-1];
                } else {
                    dp[i_cell][j_cell] = (dp[i_cell][j_cell-1] % 1000000007 + dp[i_cell-1][j_cell] % 1000000007) % 1000000007;
                }
            }
        }
    }

    return dp[i][j];
}

int main() {
    int n; cin >> n;
    vector<vector<char>> cell(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for(int j=0; j<n; ++j) {
            char c; cin >> c;
            cell[i][j] = c;
        }
    }

    int res = solve(cell, n-1, n-1, dp);
    cout << res << endl;

    return 0;
}