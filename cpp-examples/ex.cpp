#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
    public:
        int a;
        int b;
    node(int a, int b){
        this->a = a;
        this->b = b;
    }
};


int main(){
    vector<node*> list1;
    typedef union{
             int c;
             int d;
    } tef;
    tef un1;
    //cout<<un1.c<<un1.d<<endl;
    int i = 10;
    if(i == 10){
        node* a = new node(1,2);
        list1.push_back(a);
    }
    //cout<<list1[0]->a<<endl;
    //cout<<list1[0]->b<<endl;
    string s = "123213";
    if(s.find(".") != string::npos) {
    string res;
    string::iterator it = s.begin();
    string temp = "";
    temp += *it;
    while(temp.compare(".") != 0) {
        //cout<<*it<<endl;
        res = *it + res;
        it++;
        temp = *it;
        //cout<<temp<<endl;
    }
    ++it;
    res += ".";
    temp = "";
    while(it != s.end()){
        temp = *it + temp;
        it++;
    }
    //cout<<temp<<endl;
    res += temp;
    cout<<res<<endl;
    }
    else{
        string::iterator it = s.begin();
        string res;
        while(it != s.end()){
            res = *it + res;
            it++;
        }
        cout<<res<<endl;
    }
}
