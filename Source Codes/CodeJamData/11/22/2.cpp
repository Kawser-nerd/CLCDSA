#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int c,d;
int p[222];
int v[222];

bool good(ll t){
	if(t<=2)
		t=t;
	ll last = -1000000000000000000ll;
	REP(i,c){
		ll beg = p[i] - t;
		beg = max(beg, last + d);
		ll end  = beg + d*ll(v[i]-1);

		if(end > p[i] + t) return 0;

		last = end;
	}
	return 1;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>c>>d;d*=2;
		REP(i,c) scanf("%d %d",p+i,v+i),p[i]*=2;
		ll a = 0;
		ll b = 1000000000000000000ll;
		ll best = 0;
		while(a<=b){
			ll s = (a+b)/2;
			if(good(s)) best = s, b = s-1;
			else a = s +1;
		}
		printf("Case #%d: ",TC+1);
		cout<<best/2<<"."<<(best%2?"5":"0")<<endl;
	}
	return 0;
}