#include <iostream>
#include <string>
using namespace std;

int R, C;
int ht[111][111];
int lbl[111][111];

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int cl = 0;
int dfs(int r, int c)
{
	if (lbl[r][c] != -1) return lbl[r][c];

	int low = ht[r][c], ld = -1;
	
	for (int d = 0; d < 4; d++)
	{
		unsigned nr = r + dr[d], nc = c + dc[d];
		if (nr < R && nc < C && ht[nr][nc] < low)
			low = ht[nr][nc], ld = d;
	}

	if (ld == -1)
		return lbl[r][c] = cl++;
	else
		return lbl[r][c] = dfs(r + dr[ld], c + dc[ld]);
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int N; cin >> N;
	for (int T = 0; T < N; T++)
	{
		cin >> R >> C;
		for (int i = 0;i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> ht[i][j];

		printf("Case #%d:\n", T+1);

		cl = 0;
		memset(lbl, -1, sizeof lbl);
		for (int i = 0; i < R; i++)	
			for (int j = 0; j < C; j++)
				dfs(i, j);

		char mapping[11100];
		memset(mapping, -1, sizeof mapping);

		char cur = 'a';
		for (int i = 0; i < R; i++, cout << endl)
			for (int j = 0; j < C; j++)
			{
				if (mapping[lbl[i][j]] == -1)
					mapping[lbl[i][j]] = cur++;
				if (j) cout << " ";
				cout << mapping[lbl[i][j]];
			}
	}
}