#include <stdio.h>
#include <string.h>

int tc, ntc;
int n, m;

#define MOD 10007

int dp[101][101];
bool stat[101][101];

int doit(int y, int x)
{
	if (y>n || x>m) return 0;
	if (y==n && x==m) return 1;
	if (stat[y][x]) return 0;
	
	int &res = dp[y][x];
	if (res != -1) return res;
	
	res = doit(y+2,x+1) + doit(y+1, x+2);
	res %= MOD;
	return res;
}

int main()
{
	scanf("%d",&ntc);
	int k;
	int i, j;
	int a, b;
	int res;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d %d %d",&n,&m,&k);
		memset(stat,0,sizeof(stat));
		for (i=0; i<k; i++)
		{
			scanf("%d %d",&a,&b);
			stat[a][b] = true;
		}
		
		memset(dp, -1, sizeof(dp));
		res = doit(1,1);
		printf("Case #%d: %d\n",tc,res);
	}
}