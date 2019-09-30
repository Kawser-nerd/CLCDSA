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
	int N,M;
	int i,j,m,c,len,ans;
	char s[105];
	static int num[105],cnt[105][105],let[105][105],cur[105];
	Read(T);
		Fox1(t,T)
		{
			printf("Case #%d: ",t);
			Read(N);
				Fox(i,N)
				{
					scanf("%s",&s);
					len=strlen(s);
					c=0;
					num[i]=0;
						Fox(j,len)
						{
							c++;
								if ((j==len-1) || (s[j]!=s[j+1]))
								{
									let[i][num[i]]=s[j];
									cnt[i][num[i]++]=c;
									c=0;
								}
						}
				}
				Fox(i,N)
					if (num[i]!=num[0])
						goto Bad;
			M=num[0];
			ans=0;
				Fox(i,M)
				{
						Fox(j,N)
						{
								if (let[j][i]!=let[0][i])
									goto Bad;
							cur[j]=cnt[j][i];
						}
					sort(cur,cur+N);
					m=cur[N/2];
						Fox(j,N)
							ans+=abs(cur[j]-m);
				}
			printf("%d\n",ans);
			continue;
Bad:;
			printf("Fegla Won\n");
		}
	return(0);
}