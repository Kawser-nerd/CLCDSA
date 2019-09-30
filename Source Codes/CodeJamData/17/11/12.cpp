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
	//freopen("A-small-attempt0.in","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	int N,M;
	int i,j,k;
	char G[30][30];
	Read(T);
		Fox1(t,T)
		{
			printf("Case #%d:\n",t);
			Read(N),Read(M);
				Fox(i,N)
					scanf("%s",&G[i]);
				Fox(i,N)
					Fox(j,M)
						if (G[i][j]!='?')
						{
							k=j-1;
								while ((k>=0) && (G[i][k]=='?'))
									G[i][k--]=G[i][j];
							k=j+1;
								while ((k<M) && (G[i][k]=='?'))
									G[i][k++]=G[i][j];
						}
				Fox(i,N)
				{
						Fox(j,M)
							if (G[i][j]!='?')
								goto Good;
					goto Skip;
Good:;
					k=i-1;
						while (k>=0)
						{
								Fox(j,M)
									if (G[k][j]!='?')
										goto Out1;
								Fox(j,M)
									G[k][j]=G[i][j];
							k--;
						}
Out1:;
					k=i+1;
						while (k<N)
						{
								Fox(j,M)
									if (G[k][j]!='?')
										goto Out2;
								Fox(j,M)
									G[k][j]=G[i][j];
							k++;
						}
Out2:;
Skip:;
				}
				Fox(i,N)
					printf("%s\n",G[i]);
		}
	return(0);
}