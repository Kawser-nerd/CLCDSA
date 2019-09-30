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
const LD EPS = 1e-9;
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

int C[1000];
vector<int> con[1000];

int rec(int i,int p)
{
	int m=1;
	int j,k,v;
		Fox(j,Sz(con[i]))
		{
			k=con[i][j];
				if (k!=p)
				{
					v=rec(k,i);
					Max(m,v+1);
				}
		}
	return(m);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	int N;
	int i,j,c,ans;
	bool vis[1000];
	Read(T);
		Fox1(t,T)
		{
			printf("Case #%d: ",t);
			Read(N);
				Fox(i,N)
					con[i].clear();
				Fox(i,N)
				{
					Read(C[i]),C[i]--;
					con[C[i]].pb(i);
				}
			ans=0;
				Fox(i,N)
					if (C[C[i]]==i)
					{
						j=C[i];
							if (j<i)
								continue;
						ans+=rec(i,j)+rec(j,i);
					}
				Fox(i,N)
				{
					Fill(vis,0);
					j=i,c=0;
						while (!vis[j])
							vis[j]=1,j=C[j],c++;
						if (j==i)
							Max(ans,c);
				}
			printf("%d\n",ans);
		}
	return(0);
}