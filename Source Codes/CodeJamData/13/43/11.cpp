#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


int n;
int a[2050];

vector <int> qu[2005];
int stIn[2005];
int ans[2005];

//Рёбра вверх

void addEdges()
{
	for (int i = 1; i <= n; i++)
	{
		int prevEq = -1;
		int prevWO = -1;
		for (int j = 0; j < n; j++)
		{
			if (a[j] == i - 1)
			{
				prevWO = j;
				continue;
			}
			if (a[j] == i)
			{
				if (prevWO != -1)
				{
					qu[prevWO].push_back(j);
					stIn[j]++;
				}
				if (prevEq != -1)
				{
					qu[j].push_back(prevEq);
					stIn[prevEq]++;
				}
				prevEq = j;
				continue;
			}
		}
	}
}

void addEdgesRev()
{
	for (int i = 1; i <= n; i++)
	{
		int prevEq = -1;
		int prevWO = -1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (a[j] == i - 1)
			{
				prevWO = j;
				continue;
			}
			if (a[j] == i)
			{
				if (prevWO != -1)
				{
					qu[prevWO].push_back(j);
					stIn[j]++;
				}
				if (prevEq != -1)
				{
					qu[j].push_back(prevEq);
					stIn[prevEq]++;
				}
				prevEq = j;
				continue;
			}
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			qu[i].clear();
			stIn[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i] );
		}
		addEdges();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i] );
		}
		addEdgesRev();

		set <int> free;

		for (int i = 0; i < n; i++)
		{
			if (stIn[i] == 0)
				free.insert(i);
		}

		for (int i = 1; i <= n; i++)
		{
			int cur = *free.begin();
			free.erase(cur);

			for (int j = 0; j < qu[cur].size(); j++)
			{
				int nx = qu[cur][j];
				stIn[nx]--;
				if (stIn[nx] == 0)
					free.insert(nx);
			}

			ans[cur] = i;
		}

		printf("Case #%d:", t + 1);
		for (int i = 0; i < n; i++)
			printf(" %d", ans[i] );
		printf("\n");

	}


	return 0;
}