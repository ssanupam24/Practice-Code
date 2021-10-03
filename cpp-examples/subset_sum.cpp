#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> s = {2, 5, 3, 6};
	int n = 10;
	int row = s.size();
	int col = n;
	vector<vector<bool>> dp(row+1, vector<bool>(col+1, 0));
	for(int j = 0; j <= row; j++)
	   dp[j][0]=1;
	for(int j = 0; j <= col; j++)
	   dp[0][j]=0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (j < s[i])
				dp[i][j] = dp[i-1][j];
			if (j >= s[i])
				dp[i][j] = dp[i][j - s[i]] || dp[i-1][j];
		}
	}
	cout<<dp[row][col];
}
