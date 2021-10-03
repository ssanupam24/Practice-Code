#include <bits/stdc++.h>

using namespace std;

int shortestChainLen(const string& start, const string& target, set<string> D) {
    if (start == target || D.find(target) == D.end())
        return 0;
    int level = 0, wordLen = start.size();
    queue<string> q;
    q.push(start);
    while(!q.empty()) {
        level++;
        string word = q.front();
        q.pop();
        cout<<word<<endl;
        for (int pos = 0; pos < word.size(); pos++) {
            char orig_char = word[pos];
            for (char c= 'a'; c <= 'z'; c++) {
                word[pos] = c;
                if (word == target) {
                    level++;
                    return level;
                }
                if (D.find(word) == D.end())
                    continue;
                D.erase(word);
                q.push(word);
            }
            word[pos] = orig_char;
        }
    }
    return 0;
}

int main() {
    set<string> D;
    D.insert("abcd");
    D.insert("ebad");
    D.insert("ebcd");
    D.insert("xyza");
    string start = "abcv";
    string target = "ebad";
    cout << "Length of shortest chain is: "
         << shortestChainLen(start, target, D);
    return 0;
}