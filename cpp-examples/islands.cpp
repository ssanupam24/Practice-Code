#include <bits/stdc++.h>

using namespace std;

bool IsSafe(const vector<vector<int>>& graph, const vector<vector<bool>>& visited, int i, int j) {
    if (i < 0 || i >= graph.size() || j < 0 || j >= graph[0].size() || visited[i][j])
        return false;
    return true;
}

void findIslands(const vector<vector<int>>& graph, vector<vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    if (IsSafe(graph, visited, i, j+1) && graph[i][j+1] == 1)
        findIslands(graph, visited, i, j+1);
    if (IsSafe(graph, visited, i+1, j+1) && graph[i+1][j+1] == 1)
        findIslands(graph, visited, i+1, j+1);
    if (IsSafe(graph, visited, i+1, j) && graph[i+1][j] == 1)
        findIslands(graph, visited, i+1, j);
    if (IsSafe(graph, visited, i, j-1) && graph[i][j-1] == 1)
        findIslands(graph, visited, i, j-1);
    if (IsSafe(graph, visited, i-1, j-1) && graph[i-1][j-1] == 1)
        findIslands(graph, visited, i-1, j-1);
    if (IsSafe(graph, visited, i+1, j-1) && graph[i+1][j-1] == 1)
        findIslands(graph, visited, i+1, j-1);
}

int main() {
    vector<vector<int>> graph ={ {1, 1, 0, 0, 0},
                                 {0, 1, 0, 0, 1},
                                 {1, 0, 0, 1, 1},
                                 {0, 0, 0, 0, 0},
                                 {1, 0, 1, 0, 1} };
    vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));
    int count = 0;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[0].size(); j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                count++;
                findIslands(graph, visited, i, j);
            }
        }
    }
    cout << count;
}