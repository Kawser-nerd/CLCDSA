#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, -1, 1};

char A[32][32];
int Res[16][16][16][16][4];
int X[16][16][4];
int Y[16][16][4];

int SolveTest(int test)
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	int i, j, k;
	FOR(i, 0, N)
		scanf("%s", A[i]);

	int sx = -1;
	int sy = -1;
	int fx = -1;
	int fy = -1;
	
	FOR(i, 0, N)
		FOR(j, 0, M)
		{
			if(A[i][j] == 'X')
			{
				fx = i;
				fy = j;
			}

			if(A[i][j] == 'O')
			{
				sx = i;
				sy = j;
			}
		}

	FOR(i, 0, N)
		FOR(j, 0, M)
			if(A[i][j] != '#')
				FOR(k, 0, 4)
				{
					int x = i;
					int y = j;
					
					while(true)
					{
						int xx = x + DX[k];
						int yy = y + DY[k];
						if(xx < 0 || xx >= N || yy < 0 || yy >= M || A[xx][yy] == '#')
							break;

						x = xx;
						y = yy;
					}

					X[i][j][k] = x;
					Y[i][j][k] = y;
				}

	CLEAR(Res, -1);
	queue< pair<PII, pair<PII, int> >> Q;
	FOR(i, 0, 4)
	{
		int x = X[sx][sy][i];
		int y = Y[sx][sy][i];
		Res[sx][sy][x][y][i] = 0;
		Q.push(MP(PII(sx, sy), MP(PII(x, y), i)));
	}

	while(!Q.empty())
	{
		sx = Q.front().first.first;
		sy = Q.front().first.second;
		int x = Q.front().second.first.first;
		int y = Q.front().second.first.second;
		int z = Q.front().second.second;
		int value = Res[sx][sy][x][y][z];
		Q.pop();

		if(sx == fx && sy == fy)
		{
			printf("Case #%d: %d\n", test + 1, value);
			return 0;
		}
		
		FOR(i, 0, 4)
		{
			int xx = sx + DX[i];
			int yy = sy + DY[i];

			if(xx < 0 || xx >= N || yy < 0 || yy >= M || A[xx][yy] == '#')
			{
				if(Res[x][y][sx][sy][i] == -1)
				{
					Res[x][y][sx][sy][i] = value + 1;
					Q.push(MP(PII(x, y), MP(PII(sx, sy), i)));
				}

				FOR(j, 0, 4)
				{
					int x1 = X[x][y][j];
					int y1 = Y[x][y][j];
					int z1 = j;
					if(Res[x][y][x1][y1][z1] == -1)
					{
						Res[x][y][x1][y1][z1] = value + 1;
						Q.push(MP(PII(x, y), MP(PII(x1, y1), z1)));
					}
				}
			}
			else
			{
				if(Res[xx][yy][x][y][z] == -1)
				{
					Res[xx][yy][x][y][z] = value + 1;
					Q.push(MP(PII(xx, yy), MP(PII(x, y), z)));
				}

				FOR(j, 0, 4)
				{
					int x1 = X[xx][yy][j];
					int y1 = Y[xx][yy][j];
					int z1 = j;
					if(Res[xx][yy][x1][y1][z1] == -1)
					{
						Res[xx][yy][x1][y1][z1] = value + 1;
						Q.push(MP(PII(xx, yy), MP(PII(x1, y1), z1)));
					}
				}
			}
		}
	}

	printf("Case #%d: THE CAKE IS A LIE\n", test + 1);

	return 0;
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
		SolveTest(t);

	return 0;
};
