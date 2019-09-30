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
	map<pair<int,int>,int> mp;
	int n,a[44]={},b[44]={},c[44]={},ma,mb;
	cin>>n>>ma>>mb;
	int ans=mod;
	FOR(i,0,n){
		cin>>a[i]>>b[i]>>c[i];
	}

	int dp[42][422][422];
	FOR(i,0,42)FOR(j,0,422)FOR(k,0,422)dp[i][j][k]=mod;
	dp[0][0][0]=0;
	FOR(ii,0,n)FOR(j,0,402)FOR(k,0,402){
		int i=ii+1;
		dp[i][j+a[ii]][k+b[ii]]=min(dp[i][j+a[ii]][k+b[ii]],dp[i-1][j][k]+c[ii]);
		dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);

	}
	FOR(coeff,1,400/ma){
		int aa=coeff*ma,bb=coeff*mb;
		if(bb>400)break;
		ans=min(ans,dp[n][aa][bb]);
	}
	if(ans==mod)cout<<-1;
	else cout<<ans;
    return 0;
}