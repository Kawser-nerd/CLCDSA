#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 17
int N, M;
int bst[MAXN][MAXN][MAXN][MAXN][MAXN][MAXN];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int nextX[MAXN][MAXN][4];
int nextY[MAXN][MAXN][4];

char map[MAXN][MAXN];

#define stare pair< pair<int, int>, pair< pair<int, int>, pair<int, int> > >
#define sX first.first
#define sY first.second
#define yX second.first.first
#define yY second.first.second
#define bX second.second.first
#define bY second.second.second

inline stare make_stare(int SX, int SY, int YX, int YY, int BX, int BY)
{
	return make_pair(make_pair(SX, SY), make_pair(make_pair(YX, YY), make_pair(BX, BY)));
}

queue< stare > Q[2];

inline int x_ok(int val)
{
	return val >= 0 && val < N;
}

inline int y_ok(int val)
{
	return val >= 0 && val < M;
}

inline void update(int SX, int SY, int YX, int YY, int BX, int BY, int val)
{
	if (val < bst[SX][SY][YX][YY][BX][BY])
	{
		bst[SX][SY][YX][YY][BX][BY] = val;
		Q[val & 1].push( make_stare(SX, SY, YX, YY, BX, BY) );
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		memset(bst, 0x3f, sizeof(bst));
		int Sx, Sy, Dx, Dy;
		Sx = Sy = Dx = Dy = -1;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				scanf(" %c", map[i] + j);
				if (map[i][j] == 'O')
					Sx = i, Sy = j;
				if (map[i][j] == 'X')
					Dx = i, Dy = j;
			}
		/*printf("%d %d\n", N, M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				printf("%c", map[i][j]);
			printf("\n");
		}*/

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				for (int k = 0; k < 4; k++)
				{
					int x = i, y = j;
					for (; x_ok(x + dx[k]) && y_ok(y + dy[k]) && map[x + dx[k]][y + dy[k]] != '#'; )
						x += dx[k], y += dy[k];

					nextX[i][j][k] = x;
					nextY[i][j][k] = y;
				}

		for (; !Q[0].empty(); Q[0].pop());
		for (; !Q[1].empty(); Q[1].pop());
		bst[Sx][Sy][N][M][N][M] = 0;
		Q[0].push( make_stare(Sx, Sy, N, M, N, M) );
		int done = 0, BST = 0x3f3f3f3f;
		for (int CST = 0; !done && CST <= 10000; CST++)
			for (; !Q[CST & 1].empty() && !done; Q[CST & 1].pop())
			{
				stare cur = Q[CST & 1].front();
				int cur_val = bst[cur.sX][cur.sY][cur.yX][cur.yY][cur.bX][cur.bY];
				if (cur_val != CST)
					continue;

				if (cur.sX == Dx && cur.sY == Dy)
				{
					done = 1;
					BST = CST;
					break;
				}

				if (cur.sX == cur.yX && cur.sY == cur.yY && x_ok(cur.bX) && y_ok(cur.bY))
					update(cur.bX, cur.bY, cur.yX, cur.yY, cur.bX, cur.bY, cur_val + 1);
				for (int k = 0; k < 4; k++)
				{
					if (x_ok(cur.sX + dx[k]) && y_ok(cur.sY + dy[k]))
						if (map[cur.sX + dx[k]][cur.sY + dy[k]] != '#')
							update(cur.sX + dx[k], cur.sY + dy[k], cur.yX, cur.yY, cur.bX, cur.bY, cur_val + 1);

					int _nxtx = nextX[cur.sX][cur.sY][k];
					int _nxty = nextY[cur.sX][cur.sY][k];
					update(cur.sX, cur.sY, _nxtx, _nxty, cur.bX, cur.bY, cur_val);
					update(cur.sX, cur.sY, cur.yX, cur.yY, _nxtx, _nxty, cur_val);
				}
			}

		printf("Case #%d: ", t);
		if (BST == 0x3f3f3f3f)
			printf("THE CAKE IS A LIE\n");
		else
			printf("%d\n", BST);
	}
	return 0;
}
