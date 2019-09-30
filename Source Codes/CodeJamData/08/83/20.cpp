
// Headers {{{
#include<iostream>
#include<assert.h>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<bitset>
#include<numeric>
using namespace std;


#define FOR(I,A,B) for(int I=(A);I<=(B);++I)
#define FORD(I,A,B) for(int I=(A);I>=(B);--I)
#define REP(I,N) for(int I=0;I<(N);++I)
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();++I)
#define CLR(A,v) memset((A),v,sizeof((A)))

#define SIZE(x) ((int)((x).size()))
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef long long LL;
typedef vector<string> VS;
// }}}

const int nmx=500;
const LL mod=1000000009;
int k;
int n;
VI E[nmx];
VI S[nmx];
int P[nmx];

void sett(int v,int p){
	P[v]=p;
	S[v].clear();

	FORE(t,E[v]) if(*t!=p){
		S[v].PB(*t);
		sett(*t,v);
	}
}

LL	 fix(LL k,int il){
	LL res=1;
	REP(i,il){
		res*=(LL)(k-i);
		res%=mod;
	}
	return res;

}

LL fun(int v,LL us){
	if(!SIZE(S[v])){
		if(us > k ) return 0;
		return 1;
	}
	int sn=SIZE(S[v]);
	if (k-sn-us < 0 ) return 0;
	LL res=fix(k-us,sn);
	int used=sn;
	if (P[v]!=-1) used++;
	REP(i,sn)
	{
		res*=fun(S[v][i],used);
		res%=mod;
	}	
	return res%mod;
}


int main()
{
	int z; scanf("%d",&z);
	REP(zz,z)
	{
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		scanf("%d%d",&n,&k);
		REP(i,n) E[i].clear();
		int a,b;
		REP(i,n-1){
			scanf("%d%d",&a,&b);
			--a;--b;	
			E[a].PB(b);
			E[b].PB(a);
		}
		sett(0,-1);
		printf("Case #%d: %lld\n",zz+1,fun(0,0));
	}
	return 0;
}
