#include <bits/stdc++.h>

using namespace std;

void printPath(const vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        if (i > 0)
            cout << " ";
        cout<<path[i];
    }
}

bool IsSafe(const vector<vector<int>>& graph, const vector<int>& path,
            int i, int v, const set<int>& visited) {
    if (graph[path[v-1]][i] == 0)
        return false;
    if (visited.find(i) != visited.end())
        return false;
    return true;
}

bool HamilpathUtil(const vector<vector<int>>& graph,
                   vector<int>& path, int v, set<int>& visited) {
    if (v == graph.size()) {
        if (graph[path[v-1]][0])
            return true;
        return false;
    }
    for (int i = 1; i < graph.size(); i++) {
        if (IsSafe(graph, path, i, v, visited)) {
            path[v] = i;
            visited.insert(i);
            if (HamilpathUtil(graph, path, v+1, visited))
                return true;
            path[v] = -1;
            visited.erase(i);
        }
    }
    return false;
}

void Hamilpath(const vector<vector<int>>& graph) {
    int p = graph.size();
    vector<int> path(p, -1);
    path[0] = 0;
    set<int> visited;
    visited.insert(0);
    if (HamilpathUtil(graph, path, 1, visited)) {
        printPath(path);
        return;
    }
    cout <<"No Hamiltonian path exists";
}

int main() {
    vector<vector<int>> graph = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
    Hamilpath(graph);
    return 0;
}
