#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();
    vector<int> dp(n+1, 0);
    int max_num = INT_MIN;
    for (int i = 1; i <= n; i++) {
        max_num = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_num = max(max_num, prices[j] + dp[i-j-1]);
        }
        dp[i] = max_num;
    }
    cout<<dp[n];
}