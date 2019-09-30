
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

const int mmx=1<<15;
const int nmx=17;
int T[nmx][nmx][mmx];
char A[nmx][nmx];
int w,h;

int fun(int y,int x,int mask){
	if(x==w) return fun(y+1,0,mask);
	if(y==h) return 0;
	if(T[y][x][mask]!=-1) return T[y][x][mask];
	T[y][x][mask]=0;
	if (A[y][x]=='.')
	{
		if(mask&(1<<x)) 
			return T[y][x][mask]=fun(y,x+1,mask^(1<<x));
		return T[y][x][mask]=fun(y,x+1,mask);
	}
	int add=4;
	if (x && mask&(1<<(x-1))) add-=2;
	if ( mask&(1<<x)) add-=2;
	T[y][x][mask]=max(T[y][x][mask],add+fun(y,x+1,mask|(1<<x)));
	if (A[y][x]=='?'){
		if(mask&(1<<x)) 
			T[y][x][mask]=max(T[y][x][mask],fun(y,x+1,mask^(1<<x)));
		else
		  	T[y][x][mask]=max(T[y][x][mask],fun(y,x+1,mask));
	}
	return T[y][x][mask];	

}











int main()
{
	int z; scanf("%d",&z);
	REP(zz,z)
	{
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		CLR(T,-1);
		scanf("%d%d",&h,&w);
		REP(y,h) scanf("%s",A[y]);


		printf("Case #%d: %d\n",zz+1,fun(0,0,0));
	}
	return 0;
}
