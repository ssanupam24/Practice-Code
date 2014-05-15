/*Author: Anupam
 *SPOJ PROBLEMS
 */

#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <utility>
#include <stdlib.h>
#define MAX 1000000

using namespace std;

bool isPrime[MAX];
struct results{
	int ordinal;
	int distance;
};

void sieve(int N,vector<int>* v) {
	bool* isPrime = new bool[N+1];
	for(int j = 0; j <=N; j++)
		isPrime[j]=true;
	isPrime[0]=false; 
	isPrime[1] = false;
 	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) {
			for (int m = 2; (m*i) <= N; m++) {
				isPrime[m*i] = false;
			}
		}
	}
	for(int i =0; i <=N; i++){
		if(isPrime[i]== true)
			v->push_back(i);
		}
}

void calcPrimeFact(int c, vector<int> primeNo,vector<pair<int,int> >* primeFact){

		int count =0;
		int i=0;
		int j = sqrt(c);
		pair<int,int> foo;
		while(primeNo[i] <= j ){
			int k = c;
			if((k % primeNo[i]) == 0){
			
			while((k % primeNo[i]) == 0){
	
					count+=1;
					k/=primeNo[i];	
					}	
			foo = make_pair(primeNo[i],count);
			primeFact->push_back(foo);
			}
			//cout<<foo.first<<" "<<foo.second<<endl;
			count=0;
			i++;
			}
		//cout<<"size"<<primeFact->size()<<endl;
	} 

results* calcDistance(vector<pair<int,int> > primeFact1, vector<pair<int,int> > primeFact2){
		results* res = new results;
		int i=0;
		int j =0;
		int count =0;
		res->distance = 0;
		res->ordinal=0;
		//int k = max(primeFact1.size(),primeFact2.size());
		//cout<<"size"<<k<<endl;
		//res->ordinal = k;
		while((i < primeFact1.size()) && (j < primeFact2.size())){
			if((primeFact1[i].first == primeFact2[j].first) && (i==j)){
					res->distance+=abs(primeFact1[i].second-primeFact2[j].second);	
					}
		
				i++;
				j++;
			}
		for(i=0, j=0; i < primeFact1.size() || j < primeFact2.size();i++,j++){
			if(primeFact1[i].first == primeFact2[j].first)
				count +=1;
			if((primeFact1[i].first != primeFact2[j].first) && (i < primeFact1.size() && j < primeFact2.size())) {
				count +=2;
				res->distance +=2;
				}
			if((primeFact1[i].first != primeFact2[j].first) &&  (i > primeFact1.size() && j < primeFact2.size())) {
				count +=1;
				res->distance +=1;
				}
			if((primeFact1[i].first != primeFact2[j].first) &&  (i < primeFact1.size() && j > primeFact2.size())){
                                count +=1;
				res->distance +=1;
				}
			}
		res->ordinal = count;
		//cout<<res->distance<<" "<<res->ordinal<<endl;
		return res;
		}

int main(void){

	int a,b,c;
	vector<int> primeNo;
	sieve(1000000,&primeNo);
	int index = 1;
	while(1){
		cin>>a;
		cin>>b;
		if(a==0 || b==0)
			break;
		vector<pair<int,int> > primeFact1;
	        vector<pair<int,int> > primeFact2;
		results* res= new results;
		calcPrimeFact(a,primeNo,&primeFact1);
                calcPrimeFact(b,primeNo,&primeFact2);	
		res = calcDistance(primeFact1,primeFact2);
		cout<<index<<"."<<" "<<res->ordinal<<":"<<res->distance<<endl;
		index++;
		
}

	return 0;
}
