#include <bits/stdc++.h>

using namespace std;

void GenerateParenthesis(string cur, int n, int open, int close) {
    if (cur.size() == 2*n) {
        cout<<cur<<endl;
        return;
    }
    if (open < n)
        GenerateParenthesis(cur+"(", n, open+1, close);
    if (close < open)
        GenerateParenthesis(cur+")", n, open, close+1);
}

int main() {
    int n = 3;
    GenerateParenthesis("", 3, 0, 0);
    return 0;
}