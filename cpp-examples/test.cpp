#include <bits/stdc++.h>

using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(10);
    pq.push(1);
    cout<<pq.top();
    return 0;
}
