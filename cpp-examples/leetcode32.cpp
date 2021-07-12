#include <bits/stdc++.h>

using namespace std;

int main() {
    string str = "())))))";
    stack<int> s;
    int counter = 0;
    s.push(-1);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            s.push(i);
            continue;
        }
        s.pop();
        if (!s.empty())
            counter = max(counter, i - s.top());
        else 
            s.push(i);
    }
    cout << counter;
    return 0;
}