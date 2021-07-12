#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> s = {1, 2, 3};
	int n = 4;
	vector<vector<int>> dp(n+1, vector<int>(s.size()+1, 0));
	for(int j = 0; j <s.size(); j++)
	   dp[0][j]=1;
}
