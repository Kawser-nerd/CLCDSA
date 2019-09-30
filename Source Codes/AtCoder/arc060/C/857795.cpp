#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int nxt[maxn][22],x[maxn];
int n,l,q;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	R(i,n) scanf("%d",x+i);
	scanf("%d",&l);
	F(i,1,n)
	{
		int it = upper_bound(x,x+n,x[i-1]+l) - x;
		nxt[i][0] = it;
		if(x[i-1] + l > x[n-1]) nxt[i][0] = n+1;
	}
	nxt[n+1][0] = n+1;
	F(j,1,20)
	{
		nxt[n+1][j] = n+1;
		F(i,1,n)
		{
			nxt[i][j] = nxt[nxt[i][j-1]][j-1];
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a > b) swap(a,b);
		int i = 20,ans = 0;
		while(i >= 0)
		{
			if(nxt[a][i] <= b)
			{
				a = nxt[a][i];
				ans += 1<<i;
			}
			if(a == b) break;
			--i;
		}
		if(a != b) ans++ ;
		printf("%d\n",ans);
	}
	return 0;
}