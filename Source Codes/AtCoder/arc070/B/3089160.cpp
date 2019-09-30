#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	int n,k,a[5555]={};
	cin>>n>>k;
	FOR(i,0,n){
		cin>>a[i+1];
	}
	sort(a+1,a+n+1);
	int l=0,r=n+1,m=(l+r)/2;
	while(l!=m){
		int dp[2][10555]={},idx=0;
		dp[idx][0]=1;
		FOR(i,0,n){
			FOR(j,0,k*2+2){
				int nw=j+a[i+1];
				if(nw>k*2)nw=k*2+1;
				if(i+1!=m)dp[idx^1][j]|=dp[idx][j];
				dp[idx^1][nw]|=dp[idx][j];
				dp[idx][j]=0;
			}
			idx^=1;
		}
		FOR(i,1,k*2+2){
			dp[idx][i]+=dp[idx][i-1];
			//cerr<<i<<" "<<dp[idx][i]<<endl;
		}
		int nw=k+a[m]-1;
		if(nw>k*2)nw=k*2+1;
		if(dp[idx][nw]-dp[idx][k-1]==0){
			l=m;
		}else{
			r=m;
		}
		m=(l+r)/2;
	}
	cout<<m;
    return 0;
}