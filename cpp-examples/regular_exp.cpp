#include <bits/stdc++.h>

using namespace std;

bool matchStrings(string s, string p, int i, int j) {
    if (p.empty())
        return s.empty();

    bool first_char_match = i >= 1 && j >= 1 ? (s[0]==p[0]||p[0]=='.') : false;
    if(j >= 2 && p[1] == '*')
        return matchStrings(s, p.substr(2), i, j-2) ||(first_char_match && matchStrings(s.substr(1), p, i-1, j) );
       
    else
        return first_char_match && matchStrings(s.substr(1), p.substr(1), i-1, j-1);
}

int main() {
    string s, p;
    cout<<"enter string"<<endl;
    cin>>s;
    cout<<"enter pattern"<<endl;
    cin>>p;
    if(matchStrings(s, p, s.size(), p.size()))
        cout<<"strings match"<<endl;
    else
        cout<<"strings dont match"<<endl;
    return 0;   
}
