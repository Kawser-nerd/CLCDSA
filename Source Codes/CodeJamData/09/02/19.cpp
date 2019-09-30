#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int GO[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

#define PB push_back 
#define MP make_pair 

int H, W, al[110][110];
bool v[110][110];
vector< pair<int, int> > adj[110][110];
char c[110][110];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d %d", &H, &W);
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j) {
				scanf("%d", &al[i][j]);
				v[i][j] = false;
				adj[i][j].clear();
			}
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j) {
				int bx = -1, by = -1, bal = al[i][j];
				for (int k = 0; k < 4; ++k) {
					int dx = i + GO[k][0], dy = j + GO[k][1];
					if (0 <= dx && dx < H && 0 <= dy && dy < W && al[dx][dy] < bal) {
						bx = dx; by = dy; bal = al[dx][dy];
					}
				}
				if (bx != -1) {
					adj[i][j].PB(MP(bx, by));
					adj[bx][by].PB(MP(i, j));
				}
			}
		printf("Case #%d:\n", t + 1);
		int cnt = 0;
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j) {
				if (!v[i][j]) {
					char ch = (char)('a' + cnt++);
					queue< pair<int, int > > q;
					q.push(MP(i, j)); v[i][j] = true; c[i][j] = ch;
					while (!q.empty()) {
						int x = q.front().first, y = q.front().second; q.pop();
						for (vector< pair<int, int> >::iterator iter = adj[x][y].begin(); iter != adj[x][y].end(); ++iter)
							if (!v[iter->first][iter->second]) {
								v[iter->first][iter->second] = true;
								c[iter->first][iter->second] = ch;
								q.push(*iter);
							}
					}
				}
				printf("%c%c", c[i][j], j == W - 1 ? '\n' : ' ');
			}
		if (cnt > 26)
			while (true)
				printf("ERR\n");
	}
	return 0;
}

