#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void solve(int acase)
{
	int N, M;
	scanf("%d%d", &N, &M);
	char map[100][100];
	int complete[100][100];
	memset(complete, FALSE, sizeof complete);

	int i;
	for (i = 0; i < N; ++i)
	{
		getchar();
		scanf("%[#.]", map[i]);
	}

	int ok = TRUE;
	int j;
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
		{
			char up, cur;
			up = '.'; if (i > 0) up = map[i - 1][j];

			cur = map[i][j];

			if (i > 0 && !complete[i - 1][j])
			{
				if (cur == '.')
				{
					ok = FALSE;
					goto bad;
				}
				if (up == '/')
					map[i][j] = '\\';
				else
					map[i][j] = '/';
				complete[i][j] = TRUE;
			}
			else if (cur == '#')
			{
				if (j == 0 || map[i][j - 1] != '/' || complete[i][j - 1])
				{
					map[i][j] = '/';
					if (j == M - 1)
					{
						ok = FALSE;
						goto bad;
					}
				}
				else
					map[i][j] = '\\';
			}
			else if (cur == '.' && j > 0 && map[i][j - 1] == '/' && !complete[i][j - 1])
			{
				ok = FALSE;
				goto bad;
			}
			else
				complete[i][j] = TRUE;

			if (i == N - 1 && !complete[i][j])
			{
				ok = FALSE;
				goto bad;
			}
		}

bad:;

	printf("Case #%d:\n", acase); 
	if (ok)
	{
		for (i = 0; i < N; ++i)
			printf("%s\n", map[i]);
		int j;
		/*
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < M; ++j)
				printf("%d", complete[i][j]);
			printf("\n");
		}
		*/
	}
	else
		printf("Impossible\n");
}

int main()
{
	freopen("a0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int cases;
	scanf("%d", &cases);
	int tc;
	for (tc = 0; tc < cases; ++tc) 
		solve(tc + 1);

	return 0;
}
