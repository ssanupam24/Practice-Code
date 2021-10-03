#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> s = {2, 5, 3, 6};
	int n = 10;
	int row = n;
	int col = s.size();
	vector<vector<int>> dp(row+1, vector<int>(col, 0));
	for(int j = 0; j < col; j++)
	   dp[0][j]=1;
	for (int i = 1; i <= row; i++) {
		for (int j = 0; j < col; j++) {
			dp[i][j] = (j >= 1 ? dp[i][j-1] : 0) + (i - s[j] >= 0 ? dp[i - s[j]][j] : 0);
		}
	}
	cout<<dp[row][col-1];
}
