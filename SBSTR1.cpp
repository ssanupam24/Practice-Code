#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void compPrefix(char *t,int *pie,int m, char *p){
    pie[0] = 0;
    int k = 0;
    int q = 1;
    while(q < m){
        if(p[k] == p[q]){
            k++;
            pie[q] = k;
            q++;
        }
        else{
            if(k != 0){
                k = pie[k-1];
            }
            else{
                pie[q] = 0;
                q++;
            }
        }
    }
}

int isSubstring(char* a, char* b){
    int m = strlen(a);
    int n = strlen(b);
    int* pie = (int*)malloc(sizeof(int)*m);
    int q = 0;
    int j = 0;
    compPrefix(b,pie,m,a);
    while(q < n){
        if(a[j] == b[q]){
            q++;
            j++;
        }
        if(j == m){
            return 1;
        }
        else if(a[j] != b[q]){
            if(j != 0){
                j = pie[j -1];
            }
            q++;
        }
    }
    free(pie);
    return 0;
}

int main(){
    string a;
    string b;
    int i =0;
    while(i < 2){
        cin>>a;
        cin>>b;
        //char* a1 = strdup(a.c_str());
        //char* b1 = strdup(b.c_str());
        char* a1 = &a[0];
        char* b1 = &b[0];
        //cout<<a1<<endl;
        //cout<<b1<<endl;
        if(isSubstring(b1,a1))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
        i++;
    }
}
