#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> neighbors[400];
bool visited[400][400];
int dist[400][400], threat[400][400];
queue<pair<int, int> > Q;

void visit (int i, int j, int d, int t)
{
	if (!visited[i][j])
	{
		dist[i][j] = d; threat[i][j] = t; visited[i][j] = true;
		Q.push(make_pair(i, j));
	}
	if (t > threat[i][j])
		threat[i][j] = t;
}

int get_threat (int ot, int ff, int f, int t)
{
	int i = 0, j = 0;
	
	ot -= 1;
	if (ff == f)
		ot -= 1;
	
	int merged[400], mp;
	
	mp = merge(neighbors[ff].begin(), neighbors[ff].end(), neighbors[f].begin(), neighbors[f].end(), merged) - merged;
	
	while (i < mp || j < neighbors[t].size())
		if (i == mp)
		{
			j ++; ot ++;
		}
		else if (j == neighbors[t].size())
		{
			i ++;
		}
		else if (merged[i] == neighbors[t][j])
		{
			i ++; j ++;
		}
		else if (merged[i] < neighbors[t][j])
		{
			i ++;
		}
		else
		{
			j ++; ot ++;
		}
	
	return ot;
}

int main ()
{
	int t, ct = 0;
	
	for (scanf ("%d", &t); t > 0; t --)
	{
		scanf ("%d%d", &n, &m);
		
		for (int i = 0; i < n; i ++)
			neighbors[i].clear();
		for (int i = 0; i < m; i ++)
		{
			int a, b;
			
			scanf ("%d,%d", &a, &b);
			
			neighbors[a].push_back(b);
			neighbors[b].push_back(a);
		}
		for (int i = 0; i < n; i ++)
			sort(neighbors[i].begin(), neighbors[i].end());
		
		int b = -1;
		int d = -1;
		
		memset(visited, false, sizeof(visited));
		Q = queue<pair<int,int> >();
	
		visit (0,0, 0, neighbors[0].size());
	
		while (!Q.empty())
		{
			int y = Q.front ().first;
			int x = Q.front ().second;
			Q.pop();
		
			for (int i = 0; i < neighbors[x].size(); i ++)
			{
				if (!visited[x][neighbors[x][i]] || dist[x][neighbors[x][i]] == dist[y][x] + 1)
					visit(x, neighbors[x][i], dist[y][x] + 1, get_threat(threat[y][x], y, x, neighbors[x][i]));
				if (neighbors[x][i] == 1 && d == -1)
				{
					d = dist[y][x];
					b = threat[y][x];
				}
				if (neighbors[x][i] == 1 && dist[y][x] == d && threat[y][x] > b)
					b = threat[y][x];
			}
		}
	
		printf ("Case #%d: %d %d\n", ++ ct, d, b);
	}

	return 0;
}
