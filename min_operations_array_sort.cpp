#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findMinOperations(int n, const vector<int>& arr){
	if (arr.size() == 0)
		return 0;
	int m = arr.size();
	vector<vector<int>> grid(n+1, vector<int>(m, 0));
	for(int i = 0; i < m; i++)
		grid[0][i] = 1;
	for(int i = 1; i < n+1; i++){
		for (int j = 0; j < m; j++){
			int x = i - arr[j] >= 0 ? grid[i-arr[j]][j] : 0;
			int y = j >= 1 ? grid[i][j-1] : 0;
			grid[i][j] = x + y;
		}
	}
	return grid[n][m-1];
}

int main() {
	vector<int> arr = {2, 5, 3, 6};
	cout<<findMinOperations(10, arr)<<endl;
	return 0;
}
