#include<cstdio>
#include<map>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(){
	int n,x[100];cin>>n;
	double k;cin>>k;
	int ans=0;
	REP(i,n){
		cin>>x[i];
		if(x[i]<=k/2){
			ans+=(x[i]*2);
		}
		else ans+=((k-x[i])*2);
	}
	cout<< ans <<endl;
	return 0;
}