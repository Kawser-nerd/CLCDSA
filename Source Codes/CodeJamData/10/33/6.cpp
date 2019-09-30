#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long
int a,b,c,d,i,j,n,m,k,kolt,res;
bool busy[601][601];
int dp[601][601];
bool field[601][601];
struct ret
{
	int i,j,s;
};
int ans[601];
char str[601];
int main()
{
	/*freopen("input.txt","w",stdout);
	printf("1\n");
	n=512; m=512;
	printf("%d %d\n",n,m);
	rept(i,n)
	{
		rept(j,m/4)
		{
			a=rand()%16;
			if (a<10) printf("%d",a); else
			printf("%c",a-10+'A');
		}
		printf("\n");
	}
	exit(0);*/
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("input.txt","r",stdin);
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	gets(str);
	sscanf(str,"%d",&kolt);
	rep(hod,kolt)
	{
		cerr<<hod<<" "<<clock()<<endl;
		C(busy); C(field);
		printf("Case #%d: ",hod);
		C(ans);
		res=0;
		gets(str);
		sscanf(str,"%d%d",&n,&m);
		rept(i,n)
		{
			gets(str);
			rept(j,m/4)
			{
				a=0;
				if (str[j]>='0' && str[j]<='9') a=str[j]-'0'; else
				if (str[j]>='A' && str[j]<='Z') a=str[j]-'A'+10;
				field[i][j*4]=  (a&8)!=0;
				field[i][j*4+1]=(a&4)!=0;
				field[i][j*4+2]=(a&2)!=0;
				field[i][j*4+3]=(a&1)!=0;
			}
		}
		C(dp);
		rep(side,min(n,m))
		{
			rept(i,n)
			{
				rept(j,m)
				{
					if (dp[i][j]!=side-1) continue;
					if (i-side+1<0 || j-side+1<0) continue;
					if (side>2)
					{
						if (dp[i-1][j-1]>=side-1 && dp[i-1][j]>=side-1 && dp[i][j-1]>=side-1) dp[i][j]=side;
					} else
					if (side==1) dp[i][j]=1; else
					if (side==2)
					{
						if (field[i][j]!=field[i-1][j-1]) continue; else
						if (field[i-1][j]!=field[i][j-1]) continue; else
						if (field[i][j]==field[i][j-1]) continue; else
						dp[i][j]=2;
					}
				}
			}
		}
		FORD(side,min(n,m),1)
		{
			rept(i,n)
			{
				rept(j,m)
				{
					if (dp[i][j]<side) continue;
					if (busy[i][j] || busy[i-side+1][j] || busy[i][j-side+1] || busy[i-side+1][j-side+1]) continue;
					if (!ans[side])	++res;
					++ans[side];
					FOR(z,i-side+1,i)
					{
						FOR(o,j-side+1,j)
						{
							busy[z][o]=1;
						}
					}
				}
			}
		}
		printf("%d\n",res);
		FORD(i,600,1)
		{
			if (ans[i]) printf("%d %d\n",i,ans[i]);
		}
	}
	cerr<<clock()<<endl;
}
