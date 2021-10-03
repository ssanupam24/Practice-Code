#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr = {1, 100, 50, 100};
    int small = *min_element(arr.begin(), arr.end());
    int large = *max_element(arr.begin(), arr.end());
    vector<vector<int>> dp(arr.size(), vector<int>(large+1, 0));
    for (int i = small; i <= large; i++) {
        dp[0][i] = abs(arr[0] - i);
    }
    for (int i = 1; i < arr.size(); i++) {
        int min_elem = INT_MAX;
        for (int j = small; j <= large; j++) {
            min_elem = min(min_elem, dp[i-1][j]);
            dp[i][j] = min_elem + abs(arr[i] - j);
        }
    }
    int min_elem = INT_MAX;
    for (int i = small; i <= large; i++) {
        min_elem = min(min_elem, dp[arr.size() - 1][i]);
    }
    cout << min_elem;
    return 0;
}