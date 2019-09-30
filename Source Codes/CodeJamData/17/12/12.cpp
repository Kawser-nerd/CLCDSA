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

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=getchar();
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
	//freopen("B-small-attempt0.in","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	int N,M;
	int i,j,a,b,v,s,ans;
	int req[50],ind[50];
	vector<PR> P[50];
	vector<int> E;
	Read(T);
		Fox1(t,T)
		{
			Read(N),Read(M);
				Fox(i,N)
					Read(req[i]),P[i].clear();
			E.clear();
				Fox(i,N)
					Fox(j,M)
					{
						Read(v);
						a=v/req[i];
						b=a+1;
							while (a>0)
							{
								s=req[i]*a;
									if (v*10>s*11)
										break;
								a--;
							}
							for(;;)
							{
								s=req[i]*b;
									if (v*10<s*9)
										break;
								b++;
							}
							if (b>a+1)
							{
								P[i].pb(mp(a+1,b-1));
								E.pb(a+1);
							}
					}
			sort(All(E));
				Fox(i,N)
					sort(All(P[i])),ind[i]=0;
			ans=0;
				Fox(a,Sz(E))
				{
					v=E[a];
Rep:;
						Fox(i,N)
						{
							while ((ind[i]<Sz(P[i])) && (P[i][ind[i]].y<v))
								ind[i]++;
							if (ind[i]==Sz(P[i]))
								goto Done;
						}
						Fox(i,N)
							if (P[i][ind[i]].x>v)
								break;
						if (i==N)
						{
							ans++;
								Fox(i,N)
									ind[i]++;
							goto Rep;
						}
				}
Done:;
			printf("Case #%d: %d\n",t,ans);
		}
	return(0);
}