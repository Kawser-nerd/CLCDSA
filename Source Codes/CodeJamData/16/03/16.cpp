#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

int N=32, M=500, s=0, MS=M;
int a[100];
int blist[3]={2,6,8};
int ex[3][1000][40], plist[1010];
string ans[1000];

int checkdiv(int z, int b, int p)
{
	int rm=ex[b][p][0]+ex[b][p][N-1];
	rep(i,1,z) rm+=ex[b][p][a[i]];
	if (rm%plist[p]==0) return 1; else return 0;
}

void check(int z)
{
	static int can[3];
	rep(b,0,2)
	{
		can[b]=-1;
		rep(i,1,s)
			if (checkdiv(z,b,i))
			{
				can[b]=i; break;
			}
		if (can[b]==-1) return;
	}
	ans[M]="";
	rep(i,1,N) ans[M]+='0';
	rep(i,1,z) ans[M][N-1-a[i]]='1';
	ans[M][0]='1'; ans[M][N-1]='1';
	int flag=1;
	rep(i,M+1,MS) if (ans[i]==ans[M]) flag=0;
	if (!flag) return;
	printf("%s",ans[M].c_str());
	rep(i,2,10)
	{
		if ((i-1)%2==0)
			printf(" 2");
		else if ((i-1)%3==0)
			printf(" 3");
		else if (i==2)
			printf(" %d",plist[can[0]]);
		else if (i==6)
			printf(" %d",plist[can[1]]);
		else if (i==8)
			printf(" %d",plist[can[2]]);
	}
	printf("\n");
	M--;
}

void lemon()
{
	static int flag[1010];
	rep(i,2,1000) flag[i]=1;
	rep(i,2,1000)
		if (flag[i])
		{
			s++; plist[s]=i;
			int j=i*2;
			while (j<=1000) flag[j]=0, j+=i;
		}
	
	rep(i,1,s)
		rep(b,0,2)
		{
			ex[b][i][0]=1;
			rep(j,1,N-1)
				ex[b][i][j]=ex[b][i][j-1]*blist[b]%plist[i];
		}
	
	rep(i,1,N-2) a[i]=i;
	while (1)
	{
		random_shuffle(a+1,a+N-1);
		rep(i,1,N/6)
		{
			check(i*6-2);
			if (M==0) return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("C.in","r",stdin);
	#endif
	printf("Case #1:\n");
	lemon();
	return 0;
}

