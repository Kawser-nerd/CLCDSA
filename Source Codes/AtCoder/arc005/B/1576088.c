#include<stdio.h>

typedef struct
{
	int x;
	int y;
} Point;

int main()
{
	Point p;
	char W[3];
	int c[9][9];
	int i, j, retry;
	char push[5];

	scanf("%d%d", &p.x, &p.y);
	p.x--;
	p.y--;
	getchar();
	scanf("%s", W);
	getchar();
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
			c[i][j] = getchar();
		getchar();
	}

	push[0] = c[p.y][p.x];

	for(i = 1; i < 4; i++)
	{
		do
		{
			retry = 0;

			if(W[0] == 'R' && W[1] == '\0' && p.x == 8)
			{
				W[0] = 'L';
				retry++;
			}

			if(W[0] == 'L' && W[1] == '\0' && p.x == 0)
			{
				W[0] = 'R';
				retry++;
			}

			if(W[0] == 'U' && W[1] == '\0' && p.y == 0)
			{
				W[0] = 'D';
				retry++;
			}

			if(W[0] == 'D' && W[1] == '\0' && p.y == 8)
			{
				W[0] = 'U';
				retry++;
			}

			if(W[0] == 'R' && W[1] == 'U' && p.x == 8)
			{
				W[0] = 'L';
				retry++;
			}

			if(W[0] == 'R' && W[1] == 'U' && p.y == 0)
			{
				W[1] = 'D';
				retry++;
			}

			if(W[0] == 'R' && W[1] == 'D' && p.x == 8)
			{
				W[0] = 'L';
				retry++;
			}

			if(W[0] == 'R' && W[1] == 'D' && p.y == 8)
			{
				W[1] = 'U';
				retry++;
			}

			if(W[0] == 'L' && W[1] == 'U' && p.x == 0)
			{
				W[0] = 'R';
				retry++;
			}

			if(W[0] == 'L' && W[1] == 'U' && p.y == 0)
			{
				W[1] = 'D';
				retry++;
			}

			if(W[0] == 'L' && W[1] == 'D' && p.x == 0)
			{
				W[0] = 'R';
				retry++;
			}

			if(W[0] == 'L' && W[1] == 'D' && p.y == 8)
			{
				W[1] = 'U';
				retry++;
			}
		}
		while(retry);

		if(W[0] == 'R' && W[1] == '\0')
			push[i] = c[p.y][++p.x];

		if(W[0] == 'L' && W[1] == '\0')
			push[i] = c[p.y][--p.x];

		if(W[0] == 'U' && W[1] == '\0')
			push[i] = c[--p.y][p.x];

		if(W[0] == 'D' && W[1] == '\0')
			push[i] = c[++p.y][p.x];

		if(W[0] == 'R' && W[1] == 'U')
			push[i] = c[--p.y][++p.x];

		if(W[0] == 'R' && W[1] == 'D')
			push[i] = c[++p.y][++p.x];

		if(W[0] == 'L' && W[1] == 'U')
			push[i] = c[--p.y][--p.x];

		if(W[0] == 'L' && W[1] == 'D')
			push[i] = c[++p.y][--p.x];
	}

	push[i] = '\0';

	printf("%s\n", push);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &p.x, &p.y);
  ^
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", W);
  ^