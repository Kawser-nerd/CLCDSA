#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int testAAA;

int R, C, r, c;

#define INF 100000000
const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

struct matrix
{
	int v[10][10];
	int* operator [](int t)
	{
		return v[t];
	}
};

int search(int step, matrix& s)
{
	matrix ns;
	memset(&ns, 0, sizeof(ns));
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
		{
			ns[i][j] += s[i][j];
			if (i == r && j == c || s[i][j] <= 0)
				continue;
			int cd = -1, cm = 0;
			for (int dir = 0; dir < 4; ++dir)
			{
				int ni = i + di[dir], nj = j + dj[dir];
				if (ni < 0 || nj < 0 || ni >= R || nj >= C)
					continue;
				if (s[ni][nj] > cm)
				{
					cd = dir;
					cm = s[ni][nj];
				}
			}
			if (cd != -1)
				ns[i+di[cd]][j+dj[cd]] -= s[i][j];
		}
	if (ns[r][c] <= 0)
		return step;
	int ans = 0;
	for (int dir = 0; dir < 4 && ans != INF; ++dir)
	{
		int ni = r + di[dir], nj = c + dj[dir];
		if (ni < 0 || nj < 0 || ni >= R || nj >= C)
			continue;
		if (s[ni][nj] <= 0)
			continue;
		ns[ni][nj] -= s[r][c];
		int tmp = search(step + 1, ns);
		if (ans < tmp)
			ans = tmp;
		ns[ni][nj] += s[r][c];
	}
	if (ans == 0)
		return INF;
	return ans;
}

void work()
{
	scanf("%d%d%d%d", &C, &R, &c, &r);
	--c; --r;
	matrix s;
	memset(&s, 0, sizeof(s));
	for(int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
		{
			scanf("%d", &s[i][j]);
		}
	printf("Case #%d: ", ++testAAA);
	int ans = search(0, s);
	if (ans != INF)
		printf("%d day(s)\n", ans);
	else
		puts("forever");
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		work();
}
