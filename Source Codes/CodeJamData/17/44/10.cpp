#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

#define N 110
char S[N][N];
bool used[N][N];
int dist[N][N];
bool sight[N][N][N];
int xx[11000], yy[11000];
bool go[N][N], go2[N][N], go3[N][N];
bool uu[N];
int Link[N];
int r, c, m;
int len1, len2;
int x1[N], x2[N], y1[N], y2[N];
bool live[N][N], used1[N], used2[N];

int tx[4] = {-1, 0, 1, 0}, ty[4] = {0, 1, 0, -1};

void dfs(int x, int y, int k, int p) {
	if (x < 1 || x > r || y < 1 || y > c)
		return ;
	if (S[x][y] == '#')
		return ;
	sight[x][y][p] = true;
	dfs(x + tx[k], y + ty[k], k, p);
}

void bfs(int x, int y, int k) {
	int q, h;
	q = h = 1;
	xx[q] = x;
	yy[q] = y;
	dist[x][y] = 0;
	memset(used, false, sizeof used);
	used[x][y] = true;
	while (q <= h) {
		if (dist[xx[q]][yy[q]] < m) {
			for (int t = 0; t < 4; t++) {
				int X = xx[q] + tx[t], Y = yy[q] + ty[t];
				// printf("?? %d %d %d %d\n", X, Y, r, c);
				if (1 <= X && X <= r && 1 <= Y && Y <= c && !used[X][Y] && S[X][Y] != '#') {
					used[X][Y] = true;
					h += 1;
					dist[X][Y] = dist[xx[q]][yy[q]] + 1;
					xx[h] = X;
					yy[h] = Y;
				}
			}
		}
		q += 1;
	}
	// printf("?? %d %d\n", k, h);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= len2; j++)
			if (sight[xx[i]][yy[i]][j]) {
				// printf("xx %d %d\n", k, j);
				go[k][j] = true;
			}
	}
}

void bfs2(int x, int y, int k) {
	int q, h;
	q = h = 1;
	xx[q] = x;
	yy[q] = y;
	dist[x][y] = 0;
	memset(used, false, sizeof used);
	used[x][y] = true;
	while (q <= h) {
		if (dist[xx[q]][yy[q]] < m && !live[xx[q]][yy[q]]) {
			for (int t = 0; t < 4; t++) {
				int X = xx[q] + tx[t], Y = yy[q] + ty[t];
				// printf("?? %d %d %d %d\n", X, Y, r, c);
				if (1 <= X && X <= r && 1 <= Y && Y <= c && !used[X][Y] && S[X][Y] != '#') {
					used[X][Y] = true;
					h += 1;
					dist[X][Y] = dist[xx[q]][yy[q]] + 1;
					xx[h] = X;
					yy[h] = Y;
				}
			}
		}
		q += 1;
	}
	// printf("?? %d %d\n", k, h);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= len2; j++)
			if (!used2[j] && sight[xx[i]][yy[i]][j]) {
				// printf("xx %d %d\n", k, j);
				go2[k][j] = true;
			}
	}
}

void calc_direct() {
	memset(go2, 0, sizeof go2);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			live[i][j] = false;
			for (int p = 1; p <= len2; p++)
				if (!used2[p] && sight[i][j][p])
					live[i][j] = true;
		}
	for (int i = 1; i <= len1; i++)
		bfs2(x1[i], y1[i], i);
}

bool fi(int k) {
	for (int j = 1; j <= len2; j++)
		if (go[k][j] && !uu[j]) {
			uu[j] = true;
			if (!Link[j] || fi(Link[j])) {
				Link[j] = k;
				return true;
			}
		}
	return false;
}

int MAX() {
	int ans = 0;
	memset(Link, 0, sizeof Link);
	for (int i = 1; i <= len1; i++) {
		memset(uu, false, sizeof uu);
		if (fi(i)) {
			ans += 1;
		}
	}
	return ans;
}

void doit() {
	scanf("%d%d%d", &c, &r, &m);
	for (int i = 1; i <= r; i++)
		scanf("%s", S[i] + 1);
	memset(sight, false, sizeof sight);
	len1 = len2 = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			if (S[i][j] == 'S') {
				len1 += 1;
				x1[len1] = i;
				y1[len1] = j;
			}else if (S[i][j] == 'T') {
				len2 += 1;
				x2[len2] = i;
				y2[len2] = j;
				for (int k = 0; k < 4; k++)
					dfs(i, j, k, len2);
			}
		}

	memset(go, 0, sizeof go);
	for (int i = 1; i <= len1; i++) {
		bfs(x1[i], y1[i], i);
	}

	int ans = MAX();
	
	printf("%d\n", ans);
	memset(used1, false, sizeof used1);
	memset(used2, false, sizeof used2);
	int ANS = ans;
	while (ans--) {
		calc_direct();
		bool fin = false;
		for (int i = 1; i <= len1 && !fin; i++)
			for (int j = 1; j <= len2 && !fin; j++)
				if (!used1[i] && !used2[j] && go2[i][j]) {
					// printf("pupu %d %d\n", i, j);
					memcpy(go3, go, sizeof go);
					memset(go[i], false, sizeof go[i]);
					go[i][j] = true;
					if (MAX() == ANS) {
						printf("%d %d\n", i, j);
						used1[i] = true;
						used2[j] = true;
						fin = true;
						break;
					}else {
						memcpy(go, go3, sizeof go);
					}
				}
	}
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        doit();
    }
}