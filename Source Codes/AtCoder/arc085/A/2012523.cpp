#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
 
#define MOD (long long int)(1e9+7)
#define ll long long int


int main(void){
	int n,m;
	cin>>n>>m;
	int run;
	run=(n-m)*100+m*1900;
	for(int i=0;i<m;i++){
		run=run*2;
	}
	cout<<run<<endl;
	return 0;	
}