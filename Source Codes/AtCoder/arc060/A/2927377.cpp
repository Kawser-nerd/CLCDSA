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
	int n,a,in[52]={};
	cin>>n>>a;
	FORQ(i,1,n){
		cin>>in[i];
		in[i]-=a;
	}
	LL dp[52][5000][2];
	int idx=1;
	FOR(j,0,52)FOR(k,0,5000)FOR(i,0,2)dp[j][k][i]=0LL;
	dp[0][2500][0]=1LL;
	FORQ(i,1,n){
		FORQ(j,0,i){
			FOR(k,-i*49,i*49+1){
				dp[j][k+2500][idx]+=dp[j][k+2500][idx^1];
				if(j!=0)dp[j][k+2500][idx]+=dp[j-1][k+2500-in[i]][idx^1];
			}
		}
		idx^=1;
		FORQ(j,0,i){
			FOR(k,-i*49,i*49+1){
				dp[j][k+2500][idx]=0;
			}
		}
	}
	LL ans=0LL;
	FORQ(j,0,n){
		ans+=dp[j][2500][idx^1];
	}
	cout<<ans-1;
    return 0;
}