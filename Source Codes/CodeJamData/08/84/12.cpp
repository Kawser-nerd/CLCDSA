
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

const int nmx=1001;
const int mod[2]={59,509};
int ST[2][nmx][1<<10];
int p,n,k;







int main()
{
	int z; scanf("%d",&z);
	REP(zz,z)
	{
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		CLR(ST,0);
		scanf("%d%d%d",&n,&k,&p);
		REP(i,2)	ST[i][0][(1<<k)-1]=1;
		REP(md,2){
			REP(d,n-k){
				REP(m,1<<p){
					if(m%2 == 0 ) continue;
					if(ST[md][d][m]==0) continue;
				//	printf("md:%d d:%d m:%d %d\n",md,d,m,ST[md][d][m]);
					FOR(i,1,p){
						if( m & (1<<i)) continue;
						ST[md][d+1][(m|(1<<i))>>1]+=ST[md][d][m];
						ST[md][d+1][(m|(1<<i))>>1]%=mod[md];
					}
				}
			}
		}			
		int a=ST[0][n-k][(1<<k)-1],b=ST[1][n-k][(1<<k)-1];
		int res=0;
		FOR(i,0,mod[0]*mod[1]-1){
			if(i%mod[0]==a && i%mod[1]==b)
				res=i;
		}
		printf("Case #%d: %d\n",zz+1,res);
	}
	return 0;
}
