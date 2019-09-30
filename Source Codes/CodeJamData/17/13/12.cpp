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
	freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,tt;
	int Hd,Ad,Hk,Ak,B,D;
	int ans,d,b,t,a,a2,h,i,ad,t2,hd,hk;
	Read(T);
		Fox1(tt,T)
		{
			printf("Case #%d: ",tt);
			Read(Hd),Read(Ad),Read(Hk),Read(Ak),Read(B),Read(D);
			ans=INF;
				if (Hd<=Ak-D)
					goto Imp;
				Fox(d,Ak+1)
				{
					t=0,a=Ak,h=Hd;
						Fox(i,d)
						{
							a2=max(0,a-D);
								if (h<=a2)
								{
									t++,h=Hd-a;
										if (h<=a2)
											goto Bad;
								}
							t++,a=a2,h-=a;
						}
					ad=Ad;
						Fox(b,Hk)
						{
								if (b)
								{
										if (h<=a)
										{
											t++,h=Hd-a;
												if (h<=a)
													goto Bad;
										}
									t++,h-=a,ad+=B;
								}
							t2=t,hd=h,hk=Hk;
								while (hk>0)
								{
										if (hk<=ad)
										{
											t2++;
											break;
										}
										if (hd<=a)
										{
											t2++,hd=Hd-a;
												if (hd<=a)
													goto Bad2;
										}
									t2++,hd-=a,hk-=ad;
								}
							Min(ans,t2);
Bad2:;
						}
Bad:;
				}
Imp:;
				if (ans==INF)
					printf("IMPOSSIBLE\n");
				else
					printf("%d\n",ans);
		}
	return(0);
}