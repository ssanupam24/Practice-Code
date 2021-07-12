#include <iostream>
#include <list>
#define MAX_CHAR 256
using namespace std;

class SuffixTrieNode{
    private:
        list<int>* indexes;
        SuffixTrieNode* children[MAX_CHAR];
    public:
        SuffixTrieNode(){
            indexes = new list<int>();
            for(int i =0; i < MAX_CHAR; i++){
                children[i] = NULL;
            }
        }
        void insertSuffix(string suffix, int index);
        list<int>* search(string pat);
    };
class SuffixTrie{
    private:
        SuffixTrieNode root;
    public:
        SuffixTrie(string txt){
            for(int i =0; i < txt.length(); i++)
                root.insertSuffix(txt.substr(i),i);
        }
        void search(string pat);
};

void SuffixTrieNode::insertSuffix(string s, int index){
    indexes->push_front(index);
    if(s.length() > 0){
        char c = s.at(0);
        if(children[c] == NULL)
            children[c] = new SuffixTrieNode();
        children[c]->insertSuffix(s.substr(1),index+1);
    }
}
list<int>* SuffixTrieNode::search(string s){
    if(s.length() == 0) 
        return indexes;
    if(children[s.at(0)] != NULL)
        return (children[s.at(0)])->search(s.substr(1));
    else
        return NULL;
}
void SuffixTrie::search(string pat){
    if(pat.length() == 0) { 
        cout<<"Invalid string entered"<<endl;
        return;
    }
    list<int>* result = root.search(pat);
    if(result == NULL)
        cout<<"Pattern not found"<<endl;
    else
    {
        list<int>::iterator it;
        int len = pat.length();
        cout<<"size of the list "<<result->size()<<endl;
        for(it = result->begin(); it != result->end(); it++)
            cout<<"Pattern Found at position "<<*it - len<<endl;
    }
    
}

int main(){
    string txt = "s is a good boy";
    SuffixTrie S(txt);         
    cout << "Search for 'a'" << endl;
    S.search("a");                 
    cout << "\nSearch for 'bo'" << endl;
    S.search("bo");                      
    cout << "\nSearch for 'son'" << endl;
    S.search("son");                             
    cout << "\nSearch for 'forgeeks'" << endl;
    S.search("\0");                                     
    return 0;
}


