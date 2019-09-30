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
const LD EPS = 1e-10;
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
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	int N;
	int i,j,k,m,c,ans,num;
	LD a;
	int X[3005],Y[3005];
	LD ang[3005];
	static pair<LD,int> ang2[7005];
	Read(T);
		Fox1(t,T)
		{
			printf("Case #%d:\n",t);
			Read(N);
				Fox(i,N)
					Read(X[i]),Read(Y[i]);
				Fox(i,N)
				{
					m=0;
						Fox(j,N)
							if (i!=j)
							{
								a=atan2((LD)Y[j]-Y[i],(LD)X[j]-X[i]);
									if (a<-EPS)
										a+=2*PI;
								ang[m++]=a;
							}
					sort(ang,ang+m);
					num=c=0;
						Fox(j,m)
						{
							c++;
								if ((j==m-1) || (ang[j]<ang[j+1]-EPS))
								{
									ang2[num++]=mp(ang[j],c);
									c=0;
								}
						}
						Fox(j,num)
							ang2[num+j]=mp(ang2[j].x+2*PI,ang2[j].y);
					num<<=1;
					ans=N-1;
					k=c=0;
						Fox(j,num)
						{
Rep:;
								if (k==num)
									break;
								if (ang2[k].x<ang2[j].x+PI-EPS)
								{
									c+=ang2[k].y;
									k++;
									goto Rep;
								}
							c-=ang2[j].y;
							Min(ans,c);
						}
					printf("%d\n",ans);
				}
		}
	return(0);
}