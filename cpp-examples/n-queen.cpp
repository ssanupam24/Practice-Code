#include <bits/stdc++.h>

using namespace std;

void printQueens(const vector<vector<int>>& dp) {
    for(int i  =0; i < dp.size(); i++) {
        for(int j = 0; j < dp[0].size(); j++) {
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
}

bool IsSafe(const vector<vector<int>>& dp, int i, int j) {
    // we only check queens to the left.
    for (int k = 0; k < j; k++) {
        if (dp[i][k])
            return false;
    }
    for (int k = i, l = j; k >= 0 && l >= 0; k--, l--) {
        if (dp[k][l])
            return false;
    }
    for (int k = i, l = j; k < dp.size() && l >= 0; k++, l--) {
        if (dp[k][l])
            return false;
    }
    return true;
}

bool solveQueens(vector<vector<int>>& dp, int j) {
    if (j >= dp[0].size())
        return true;
    for (int i = 0; i < dp.size(); i++) {
        if (IsSafe(dp, i, j)) {
            dp[i][j] = 1;
            if (solveQueens(dp, j+1)) {
                return true;
            }
            dp[i][j] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> dp(4, vector<int>(4, 0));
    if (solveQueens(dp, 0))
        cout<<"N-Queen is solved"<<endl;
    printQueens(dp);
    return 0;
}
