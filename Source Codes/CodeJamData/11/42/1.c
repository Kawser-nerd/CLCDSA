#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 505

long long int GetVal (long long int a[MAXN][MAXN], int x, int y)
{
	if ((x < 0) || (y < 0)) return 0LL;
	else return a[x][y];
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static char s[MAXN];
	static int m[MAXN][MAXN];
	static long long int PX[MAXN][MAXN];
	static long long int QX[MAXN][MAXN];
	static long long int PY[MAXN][MAXN];
	static long long int QY[MAXN][MAXN];
	for (iT = 0; iT < T; iT++)
	{
		memset(PX,0,sizeof(PX));
		memset(QX,0,sizeof(QX));
		memset(PY,0,sizeof(PY));
		memset(QY,0,sizeof(QY));
		int N, M, D;
		scanf("%d %d %d\n",&N,&M,&D);
		int i, j;
		for (i = 0; i < N; i++)
		{
			scanf("%s\n",s);
			for (j = 0; j < M; j++)
			{
				m[i][j] = D + (int)(s[j] - '0');
			}
		}
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				PX[i][j] = (long long int)(i) * (long long int)(m[i][j]) + GetVal(PX,i-1,j) + GetVal(PX,i,j-1) - GetVal(PX,i-1,j-1);
				QX[i][j] = (long long int)(m[i][j]) + GetVal(QX,i-1,j) + GetVal(QX,i,j-1) - GetVal(QX,i-1,j-1);
				PY[i][j] = (long long int)(j) * (long long int)(m[i][j]) + GetVal(PY,i-1,j) + GetVal(PY,i,j-1) - GetVal(PY,i-1,j-1);
				QY[i][j] = (long long int)(m[i][j]) + GetVal(QY,i-1,j) + GetVal(QY,i,j-1) - GetVal(QY,i-1,j-1);
			}
		}
		printf("Case #%d: ",iT+1);
		char flag = 0;
		int S;
		if (N < M) S = N;
		else S = M;
		while (S >= 3)
		{
			for (i = 0; (i+S-1) < N; i++)
			{
				for (j = 0; (j+S-1) < M; j++)
				{
					long long int px = GetVal(PX,i+S-1,j+S-1) - GetVal(PX,i-1,j+S-1) - GetVal(PX,i+S-1,j-1) + GetVal(PX,i-1,j-1);
					long long int qx = GetVal(QX,i+S-1,j+S-1) - GetVal(QX,i-1,j+S-1) - GetVal(QX,i+S-1,j-1) + GetVal(QX,i-1,j-1);
					long long int py = GetVal(PY,i+S-1,j+S-1) - GetVal(PY,i-1,j+S-1) - GetVal(PY,i+S-1,j-1) + GetVal(PY,i-1,j-1);
					long long int qy = GetVal(QY,i+S-1,j+S-1) - GetVal(QY,i-1,j+S-1) - GetVal(QY,i+S-1,j-1) + GetVal(QY,i-1,j-1);
					int x, y;
					
					x = i; y = j;
					px -= (long long int)(x) * (long long int)(m[x][y]);
					qx -= (long long int)(m[x][y]);
					py -= (long long int)(y) * (long long int)(m[x][y]);
					qy -= (long long int)(m[x][y]);

					x = i; y = j+S-1;
					px -= (long long int)(x) * (long long int)(m[x][y]);
					qx -= (long long int)(m[x][y]);
					py -= (long long int)(y) * (long long int)(m[x][y]);
					qy -= (long long int)(m[x][y]);					

					x = i+S-1; y = j;
					px -= (long long int)(x) * (long long int)(m[x][y]);
					qx -= (long long int)(m[x][y]);
					py -= (long long int)(y) * (long long int)(m[x][y]);
					qy -= (long long int)(m[x][y]);

					x = i+S-1; y = j+S-1;
					px -= (long long int)(x) * (long long int)(m[x][y]);
					qx -= (long long int)(m[x][y]);
					py -= (long long int)(y) * (long long int)(m[x][y]);
					qy -= (long long int)(m[x][y]);					

					px *= 2LL;
					py *= 2LL;
					if (((px % qx) == 0LL) && (py % qy == 0LL))
					{
						long long int nx, ny;
						nx = px / qx;
						ny = py / qy;
						if (((i+(i+S-1)) == nx) && ((j+(j+S-1)) == ny))
						{
							printf("%d\n",S);
							flag = 1;
							break;
						}
					}
				}
				if (flag) break;
			}
			if (flag) break;
			S--;
		}
		if (!flag) printf("IMPOSSIBLE\n");
	}
	return 0;
}
