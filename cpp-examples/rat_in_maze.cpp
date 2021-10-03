#include <bits/stdc++.h>

using namespace std;

void printMaze(vector<vector<int>> dp) {
    for(int i  =0; i < dp.size(); i++) {
        for(int j = 0; j < dp[0].size(); j++) {
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
}

bool IsSafe(const vector<vector<int>>& maze, int i, int j) {
    if (i < 0 || j < 0 || i >= maze.size() || j >= maze[0].size() || maze[i][j] == 0)
        return false;
    return true;
}

bool solveMaze(const vector<vector<int>>& maze, vector<vector<int>>& dp, int i, int j) {
    if (i == maze.size() -1 && j == maze[0].size()-1 && maze[i][j] == 1) {
        dp[i][j] = 1;
        return true;
    }
    if (IsSafe(maze, i, j)) {
        dp[i][j] = 1;
        if (solveMaze(maze, dp, i+1, j))
            return true;
        if (solveMaze(maze, dp, i, j+1))
            return true;
        dp[i][j] = 0;
        return false;
    }
    return false;
}

int main() {
    vector<vector<int>> maze = { { 1, 0, 0, 0 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 1 } };
    vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), 0));
    if (solveMaze(maze, dp, 0, 0))
        cout<<"Maze is solved"<<endl;
    printMaze(dp);
    return 0;
}
