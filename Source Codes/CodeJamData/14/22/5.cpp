#define DEBUG 1

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
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

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const double EPS = 1e-9;
const LD PI = acos(-1.0);

#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar_unlocked
#endif

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	int A,B,K;
	int i,a,b,k,d1,d2,d3,v,a2,b2,k2;
	LL d;
	int digA[32],digB[32],digK[32];
	static LL dyn[33][2][2][2]; //[dig][=A][=B][=K]
	Read(T);
		Fox1(t,T)
		{
			printf("Case #%d: ",t);
			Read(A),Read(B),Read(K);
			v=A;
				FoxR(i,32)
					digA[i]=v&1,v>>=1;
			v=B;
				FoxR(i,32)
					digB[i]=v&1,v>>=1;
			v=K;
				FoxR(i,32)
					digK[i]=v&1,v>>=1;
			Fill(dyn,0);
			dyn[0][1][1][1]=1;
				Fox(i,32)
					Fox(a,2)
						Fox(b,2)
							Fox(k,2)
								if (d=dyn[i][a][b][k])
									Fox(d1,2)
										Fox(d2,2)
										{
											d3=d1&d2;
												if ((a) && (d1>digA[i]))
													continue;
												if ((b) && (d2>digB[i]))
													continue;
												if ((k) && (d3>digK[i]))
													continue;
											a2=((a && d1==digA[i]) ? 1 : 0);
											b2=((b && d2==digB[i]) ? 1 : 0);
											k2=((k && d3==digK[i]) ? 1 : 0);
											dyn[i+1][a2][b2][k2]+=d;
										}
			printf("%lld\n",dyn[32][0][0][0]);
		}
	return(0);
}