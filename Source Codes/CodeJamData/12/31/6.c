#include <stdio.h>

int T, N;
int edges[1024][1024];
int sons[1024];
int to_me[1024];
int marks[1024];
int OK;

void dfs(int to)
{
	int i;

	if (OK)
		return;

	if (marks[to])
	{
		OK = 1;
		return;
	}

	marks[to] = 1;

	for (i = 1; i <= N; i++)
	{
		if (edges[to][i])
			dfs(i);
	}
}

int main(void)
{
	int now, i, j, tmp;

	scanf("%d", &T);

	now = T;

	while (now--)
	{
		OK = 0;

		scanf("%d", &N);

		for (i = 1; i <= N; i++)
			to_me[i] = 0;

		for (i = 1; i <= N; i++)
		{
			sons[i] = 0;
			for (j = 1; j <= N; j++)
				edges[i][j] = 0;

			scanf("%d", &sons[i]);
	
			for (j = 0; j < sons[i]; j++)
			{
				scanf("%d", &tmp);
				edges[i][tmp] = 1;
				to_me[tmp]++;
			}
		}


		for (i = 1; i <= N; i++)
		{
			if (to_me[i])
				continue;

			if (!sons[i])
				continue;

			for (j = 1; j <= N; j++)
				marks[j] = 0;
			dfs(i);
			if (OK)
				break;;
		}

		printf("Case #%d: %s\n", T - now, OK ? "Yes" : "No");

	}
}
