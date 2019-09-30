#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BAD '@'
char map[520][520];
void remove(int i, int j, int M, int N, int d)
{
	for (int k = 0; k < d; k++)
	{
map[i][j+k] = BAD;
	}
	return;
}
int test(int i, int j, int M, int N, int d)
{
	if (i < 0 || i >= M) return 0;
	if (j < 0 || ((j+d-1) >= N)) return 0;
if (map[i][j] == BAD) return 0;
	for (int k = 1; k < d; k++)
	{
if (map[i][j+k] == BAD) return 0;
		if (map[i][j+k] == map[i][j+k-1])
		{
			return 0;
		}
	}
	return 1;
}
void printmap(int M, int N)
{
return;
	printf("MAP\n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
printf("%c", map[i][j]);
		}
printf("\n");
	}
}
int main()
{
	char buf[256];
	int TC;

int c2v[256];
c2v['0'] = 0;
c2v['1'] = 1;
c2v['2'] = 2;
c2v['3'] = 3;
c2v['4'] = 4;
c2v['5'] = 5;
c2v['6'] = 6;
c2v['7'] = 7;
c2v['8'] = 8;
c2v['9'] = 9;
c2v['A'] = c2v['a'] = 10;
c2v['B'] = c2v['b'] = 11;
c2v['C'] = c2v['c'] = 12;
c2v['D'] = c2v['d'] = 13;
c2v['E'] = c2v['e'] = 14;
c2v['F'] = c2v['f'] = 15;

	fgets(buf, 255, stdin);
	sscanf(buf, "%d", &TC);

	for (int tc = 1; tc <= TC; tc++)
	{
int M, N;
buf[0] = 0;
		memset(map, 0, sizeof(map));
		fgets(buf, 255, stdin);
		sscanf(buf, "%d %d", &M, &N);

		for (int i = 0; i < M; i++)
		{
buf[0] = 0;
			fgets(buf, 255, stdin);
//printf("Input = %s\n", buf);
			for (int j = 0; j < N; j++)
			{
int v = c2v[buf[j/4]];
map[i][j] = ((v & (0x01<<(3-(j%4)))) > 0? '1': '0');
			}
//printmap(M, N);
		}

//printmap(M, N);
int all_res = 0;
int res[520];
memset(res, 0, sizeof(res));
		int maxD = (M>N?N:M);
//printf("maxD = %d\n", maxD);
for (int d = maxD; d > 0; d--)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
int bingo = 0;
if (i+d-1 < M)
{
bingo = 1;
for (int k = 0; k < d; k++)
{
if (map[i+k][j] == BAD) {
bingo = 0; break; }
if (k > 0 && (map[i+k][j] == map[i+k-1][j]))
{
//printf("Test %d %d Failed\n", i+k, j);

	bingo = 0;
	break;
}
	if (!test(i+k, j, M, N, d))
	{
		bingo = 0;
		break;
	}
}
}
if (bingo)
{
	for (int k = 0; k < d; k++)
	{
		remove(i+k, j, M, N, d);
	}
//printmap(M, N);
res[d]++;
}
		}
	}
if (res[d] > 0) all_res++;
}

		printf("Case #%d: ", tc);
printf("%d\n", all_res);
for (int i = maxD; i > 0; i--)
{
	if (res[i] > 0)
	{
		printf("%d %d\n", i, res[i]);
	}
}
	}

	return 0;
}
