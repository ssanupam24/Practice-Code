#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    string s = " &&& ( 112 345 ";
    string final_str;
    char* strfinal;
if(s.compare("") == 0 || s.compare(" ") == 0) 
   strfinal = "";
else {
    char* str = new char[s.length()+1];
    strcpy(str,s.c_str());
    char* p = strtok(str," ");
    string spaces = " ";
    while(p != 0){
        final_str = spaces + p + final_str;
        p = strtok(NULL, " ");
    }
    strfinal =&final_str[1];
    //cout<<strfinal;
    delete[] str;
    }
 cout<<strfinal<<endl;
 return 0;
}
