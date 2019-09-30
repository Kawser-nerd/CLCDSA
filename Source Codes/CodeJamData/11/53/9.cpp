#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<stack>

using namespace std;

const int maxn = 205;

int n, m;
char g[maxn][maxn];
vector<int> out[maxn * maxn], in[maxn * maxn];

int id(int x, int y)
{
	x = (x + n) % n;
	y = (y + m) % m;

	return x * m + y;
}

void add(int x, int y)
{
	out[x].push_back(y);
	in[y].push_back(x);
}

int list[maxn * maxn];
int N;

bool fix[maxn * maxn];
bool vis[maxn * maxn];

void dfs(int x)
{
	if(vis[x]) return;
	vis[x] = true;

	for(int i=0; i<out[x].size(); i++)
	{
		int y = out[x][i];
		for(int j=0; j<in[y].size(); j++)
			dfs(in[y][j]);
	}
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test=1; test<=ntest; test++)
	{
		fprintf(stderr, "%d\n", test);

		scanf("%d%d", &n, &m);
		N = n * m;

		for(int i=0; i<n*m; i++)
		{
			in[i].clear();
			out[i].clear();
		}

		for(int i=0; i<n; i++)
		{
			scanf("%s", g[i]);
			for(int j=0; j<m; j++)
			{
				if(g[i][j] == '-')
				{
					add(id(i,j), id(i,j-1));
					add(id(i,j), id(i,j+1));
				}
				else if(g[i][j] == '|')
				{
					add(id(i,j), id(i-1,j));
					add(id(i,j), id(i+1,j));
				}
				else if(g[i][j] == '/')
				{
					add(id(i,j), id(i-1,j+1));
					add(id(i,j), id(i+1,j-1));
				}
				else
				{
					add(id(i,j), id(i+1,j+1));
					add(id(i,j), id(i-1,j-1));
				}
			}
		}

		printf("Case #%d: ", test);

		int BEGIN = 0, END = 0;
		bool zero = false;

		for(int i=0; i<N; i++)
		{
			if(in[i].size() == 1)
			{
				list[END++] = i;
			}
			else if(in[i].size() == 0)
				zero = true;
		}

		if(zero)
		{
			printf("0\n");
			continue;
		}

		memset(fix, 0, sizeof(fix));

		while(BEGIN < END)
		{
			int x = list[BEGIN++];
			int y = in[x][0];

			fix[y] = true;

			int z = out[y][0];
			if(z == x) z = out[y][1];
			
			for(vector<int>::iterator it = in[z].begin(); it != in[z].end(); it++)
			{
				if(*it == y)
				{
					in[z].erase(it);
					break;
				}
			}

			if(in[z].size() == 1)
			{
				list[END++] = z;
			}
			else if(in[z].size() == 0)
			{
				zero = true;
				break;
			}
		}
		
		if(zero)
		{
			printf("0\n");
			continue;
		}

		memset(vis, 0, sizeof(vis));
		int cnt = 0;

		for(int i=0; i<N; i++)
			if(!fix[i] && !vis[i])
			{
				cnt++;
				dfs(i);
			}

		int ans = 1;
		int mod = 1000003;
		for(int i=0; i<cnt; i++)
			ans = ans * 2 % mod;

		printf("%d\n", ans);
	}
	return 0;
}
