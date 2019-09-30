#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define For(i,n) for (i=0; i<int(n); i++)
#define ForR(i,n) for (i=int(n)-1; i>=0; i--)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0
#define LIM 101

int main()
{
	//files
	freopen("in.in","r",stdin);
		if (!DEBUG)
			freopen("out.txt","w",stdout);
	//vars
	int tt,TT;
	int N,M;
	int i,j,i2,j2,x;
	LL t,d,cur1,cur2,cur,ans;
	static LL num1[LIM],typ1[LIM],num2[LIM],typ2[LIM];
	static LL dyn[LIM][LIM];
	//testcase loop
	scanf("%d",&TT);
		For(tt,TT)
		{
			//init
			printf("Case #%d: ",tt+1);
			//input
			scanf("%d%d",&N,&M);
				For(i,N)
					scanf("%lld %lld",&num1[i],&typ1[i]);
				For(i,M)
					scanf("%lld %lld",&num2[i],&typ2[i]);
			//DP
			ans=0;
			Fill(dyn,0);
				For(i,N+1)
					For(j,M+1)
					{
						//new answer?
						ans=max(ans,dyn[i][j]);
						//try matching each type
							if ((i==N) || (j==M))
								continue;
							For(x,2)
							{
								if (x==0)
									t=typ1[i];
								else
									t=typ2[j];
								if (typ1[i]==t)
									cur1=num1[i];
								else
									cur1=0;
								if (typ2[j]==t)
									cur2=num2[j];
								else
									cur2=0;
								for (i2=i,j2=j,d=dyn[i][j]; (i2<N) && (j2<M); )
								{
									//skip 1 ahead to correct type
										if (!cur1)
										{
											i2++;
												while ((i2<N) && (typ1[i2]!=t))
													i2++;
												if (i2==N)
													break;
											cur1=num1[i2];
										}
									//skip 2 ahead to correct type
										if (!cur2)
										{
											j2++;
												while ((j2<M) && (typ2[j2]!=t))
													j2++;
												if (j2==M)
													break;
											cur2=num2[j2];
										}
									//match as much as possible here
									cur=min(cur1,cur2);
									cur1-=cur,cur2-=cur;
									d+=cur;
									dyn[i2+1][j2+1]=max(dyn[i2+1][j2+1],d);
								}
							}
						//match neither type
						dyn[i+1][j]=max(dyn[i+1][j],dyn[i][j]);
						dyn[i][j+1]=max(dyn[i][j+1],dyn[i][j]);
					}
			//output
			printf("%lld\n",ans);
		}
	return(0);
}