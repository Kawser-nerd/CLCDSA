#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

const int maxn = 20;
const int maxs = (1 << 15) + 1;
const int inf = 0x3f3f3f3f;

int n, m;
int G[maxn][maxn];

int fs;
int f[maxs][maxn];
int g[maxs][maxn];

void checkmin(int &x,int y)
{
	if(y < x) x = y;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1, a, b, c; i <= m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		G[a][b] = G[b][a] = c;
	}

	fs = (1 << n) - 1;
	
	for(int S = 1; S <= fs; S++)
		for(int i = 0; i < n; i++)
		{
			if((S >> i) & 1) continue;
			
			for(int j = 0; j < n; j++)
				if((S >> j) & 1) g[S][i] += G[i][j];
		}
	
	memset(f, inf, sizeof(f));
	
	f[1][0] = 0;
	for(int S = 1; S <= fs; S++)
		for(int i = 0; i < n; i++)
			if((S >> i) & 1)
			{
				for(int s = (S - 1) & S; s; s = (s - 1) & S)
					if((s >> i) & 1)
					{
						int val = 0;
					
						for(int j = 0; j < n; j++)
							if(i != j && ((s >> j) & 1))
								val += g[S ^ s][j];
						
						checkmin(f[S][i], f[s][i] + val);
					}
				
				for(int j = 0; j < n; j++)
					if((S >> j) & 1)
					{
						if(!G[j][i]) continue;
						
						int s = S ^ (1 << i);
						
						checkmin(f[S][i], f[s][j] + g[s ^ (1 << j)][i]);
					}
			}
	
	printf("%d\n", f[fs][n - 1]);
	return 0;
}