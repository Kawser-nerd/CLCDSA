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

int cnt;
int ncon[50],con[50][50];
int par[50],par2[50];
bool vis[50];

void rec(int i,int p)
{
	int j,k;
		if (par2[i]==-3)
			return;
		if ((par2[i]!=-1) && (par2[i]!=p))
			return;
	vis[i]=1;
		if (par2[i]==-1)
			cnt++;
		Fox(j,ncon[i])
		{
			k=con[i][j];
				if (!vis[k])
					rec(k,i);
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	int N,M;
	int i,j,c,cur,root;
	int nxtI,nxtV;
	int V[50];
	bool adj[50][50];
	Read(T);
		Fox1(t,T)
		{
			printf("Case #%d: ",t);
			Read(N),Read(M);
				Fox(i,N)
					Read(V[i]);
			Fill(ncon,0);
			Fill(adj,0);
				while (M--)
				{
					Read(i),Read(j),i--,j--;
					con[i][ncon[i]++]=j;
					con[j][ncon[j]++]=i;
					adj[i][j]=adj[j][i]=1;
				}
			Fill(par,-1);
				Fox(i,N)
				{
					nxtV=INF;
						Fox(j,N)
							if ((par[j]==-1) && (V[j]<nxtV))
							{
								memcpy(par2,par,sizeof(par));
									if (!i)
										par2[j]=-2,root=j;
									else
									{
										c=cur;
											while (!adj[c][j])
											{
													if (c==root)
														goto Bad;
												par2[c]=-3;
												c=par[c];
											}
										par2[j]=c;
									}
								cnt=i+1;
								Fill(vis,0);
								rec(root,-2);
									if (cnt==N)
									{
										nxtV=V[j];
										nxtI=j;
									}
Bad:;
							}
						if (nxtV==INF)
						{
							printf("\nBAD\n");
							return(0);
						}
					printf("%d",nxtV);
						if (!i)
							par[nxtI]=-2,root=nxtI;
						else
						{
								while (!adj[cur][nxtI])
								{
									j=par[cur];
									par[cur]=-3;
									cur=j;
								}
							par[nxtI]=cur;
						}
					cur=nxtI;
				}
			printf("\n");
		}
	return(0);
}