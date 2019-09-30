#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

const int nmax = 100;
int C[nmax][nmax], F[nmax][nmax];
double best[nmax][nmax];
bool u[nmax][nmax];

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

double perversion(int n, int m, double h)
{
	set<pair<double, pair<int,int> > > heap;
	int i, j, k;
	heap.insert(make_pair(0, make_pair(0, 0)));
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
		{
			u[i][j] = false;
			best[i][j] = 1e10;
		}
	best[0][0] = 0.0;
	while(true)
	{
		pair<int, int> cur = heap.begin() -> second;
		heap.erase(heap.begin());
		i = cur.first;
		j = cur.second;
		u[i][j] = true;
		if (i == n - 1 && j == m - 1) break;
		for(k = 0; k < 4; k++)
		{
			int newi = i + di[k];
			int newj = j + dj[k];
			if (newi < 0 || newj < 0 || newi >= n || newj >= m) continue;
			if (F[newi][newj] > C[newi][newj] - 50) continue;
			if (F[i][j] > C[newi][newj] - 50) continue;
			if (C[i][j] - 50 < F[newi][newj]) continue;
			if (u[newi][newj]) continue;
			double wait = 0.0;
			double curTime = best[i][j];
			if (h - curTime * 10 > C[newi][newj] - 50)
				wait = ((h - curTime * 10) - (C[newi][newj] - 50)) / 10.;
			double cost = curTime + wait;
			if (cost > 1e-9)
				if (h - (curTime + wait) * 10 - F[i][j] + 1e-9 < 20)
					cost += 10.;
				else
					cost += 1.;
			if (best[newi][newj] > cost)
			{
				heap.erase(make_pair(best[newi][newj], make_pair(newi, newj)));
				best[newi][newj] = cost;
				heap.insert(make_pair(best[newi][newj], make_pair(newi, newj)));
			}
		}
	}
	return best[n - 1][m - 1];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, n, m, i, j, k, h, t;

	cin >> T;
	for(t = 1; t <= T; t++)
	{
		cin >> h >> n >> m;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				cin >> C[i][j];
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				cin >> F[i][j];

		printf("Case #%d: %.8lf\n", t, perversion(n, m, h));
		

	}

	return 0;
}