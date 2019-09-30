#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

typedef vector <int> vi;

int tc, ntc;

int n, m;
char mm[20][20];

int stat[20];
vi ok;

bool check(int mask)
{
	int i;
	for (i=0; i<m-1; i++) if ((mask & (1<<i)) && (mask & (1<<(i+1)))) return false;
	return true;
}

void gen_ok()
{
	ok.clear();
	int i;
	for (i=0; i<(1<<m); i++)
	{
		if (check(i)) ok.push_back( i );
	}
}

int n1(int x)
{
	int res = 0;
	while (x)
	{
		res++;
		x &= x-1;
	}
	return res;
}

int dp[10][1024];
int doit(int y, int mask)
{
	if (y == n) return 0;
	int &res = dp[y][mask];
	if (res != -1) return res;
	
	res = 0;
	int i, a;
	for (i=0; i<ok.size(); i++)
	{
		a = ok[i] & stat[y];
		if (a != 0) continue;
		
		a = ok[i] | mask;
		if (!check(a)) continue;
		
		res >?= n1( ok[i] ) + doit(y+1, ok[i]);
	}
	return res;
}


int main()
{
	scanf("%d",&ntc);
	int i, j;
	int res;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d %d",&n,&m);
		for (i=0; i<n; i++) scanf("%s",mm[i]);
		memset(stat,0,sizeof(stat));
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++) if (mm[i][j] == 'x') stat[i] |= 1<<j;
		}
		
		gen_ok();
		//printf("%d\n",ok.size());
		
		
		memset(dp,-1,sizeof(dp));
		res = doit(0, 0);
		printf("Case #%d: %d\n",tc,res);
	}
}