#include <stdio.h>

int mapa[102][102];
char let[102][102];
int H, W;
char cur;
char dir[102][102];


int farbi(int r, int s)
{
	if (let[r][s] != 0) return;
	let[r][s] = cur;
	switch(dir[r][s])
	{
		case 1: farbi(r-1, s); break;
		case 2: farbi(r, s-1); break;
		case 3: farbi(r, s+1); break;
		case 4: farbi(r+1, s); break;
	}
	if (dir[r-1][s] == 4) farbi(r-1, s);
	if (dir[r][s-1] == 3) farbi(r, s-1);
	if (dir[r][s+1] == 2) farbi(r, s+1);
	if (dir[r+1][s] == 1) farbi(r+1, s);
}

int main()
{
	int N, t;

	scanf("%d", &N);
	for (t=1; t<=N; t++)
	{
		int i, j;

		scanf("%d %d", &H, &W);
		memset(let, 0, sizeof(let));
		for (i=1; i<=H; i++)
			for (j=1; j<=W; j++)
			{
				scanf("%d", &mapa[i][j]);
			}
		for (i=0; i<=W+1; i++)
		{
			mapa[0][i] = mapa[H+1][i] = 10000;
			dir[0][i] = dir[H+1][i] = 0;
			let[0][i] = let[H+1][i] = 'X';
		}
		for (i=0; i<=H+1; i++)
		{
			mapa[i][0] = mapa[i][W+1] = 10000;
			dir[i][0] = dir[i][W+1] = 0;
			let[i][0] = let[i][W+1] = 'X';
		}

		for (i=1; i<=H; i++)
			for (j=1; j<=W; j++)
			{
				int least = mapa[i][j];
				int d = 0;
				if (least > mapa[i-1][j]) { least = mapa[i-1][j]; d=1; }
				if (least > mapa[i][j-1]) { least = mapa[i][j-1]; d=2; }
				if (least > mapa[i][j+1]) { least = mapa[i][j+1]; d=3; }
				if (least > mapa[i+1][j]) { least = mapa[i+1][j]; d=4; }
				dir[i][j] = d;
			}

		cur = 'a';
		for (i=1; i<=H; i++)
			for (j=1; j<=W; j++)
				if (let[i][j] == 0)
				{
					farbi(i, j);
					cur++;
				}
		
		printf("Case #%d:\n", t);
		for (i=1; i<=H; i++)
		{
			for (j=1; j<=W; j++)
			{
				if (j==1)
					printf("%c", let[i][j]);
				else
					printf(" %c", let[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
