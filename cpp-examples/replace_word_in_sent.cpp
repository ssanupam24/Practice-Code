#include <bits/stdc++.h>

using namespace std;

bool FindValueinDict(const vector<string>& dictionary, const string& s) {
    return any_of(dictionary.begin(), dictionary.end(), [&](string s1){ return s1 == s;});
}

int main() {
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    string word;
    string new_sentence;
    stringstream iss(sentence);
    while (iss >> word) {
        bool found = false;
        for (int i = 1; i <= word.size(); i++) {
            string s = word.substr(0, i);
            if (FindValueinDict(dictionary, s)) {
                if (new_sentence.size() > 0)
                    new_sentence += " ";
                new_sentence += s;
                found = true;
                break;
            }
        }
        if (!found) {
            if (new_sentence.size() > 0)
                    new_sentence += " ";
            new_sentence += word;
        }
    }
    cout << new_sentence;
    return 0;
}