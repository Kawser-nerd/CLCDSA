#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
int R, C;
int U[5050], V[5050];

// 0: /, 1: \ 

int F[105][105];
int idx[505];

vector<pair<int, int> > trace_path(int y, int x, int dy, int dx)
{
	vector<pair<int, int> > ret;
/*	printf("%d %d %d %d\n", y, x, dy, dx);
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) printf("%d", F[i][j]);
		puts("");
	} */
	ret.push_back({ y, x });
	do {
		y += dy;
		x += dx;
		ret.push_back({ y, x });
		if (!(y != 0 && x != 0 && y != R + 1 && x != C + 1)) break;

		swap(dy, dx);
		if (F[y][x] == 0) {
			dy *= -1;
			dx *= -1;
		}
	} while (y != 0 && x != 0 && y != R + 1 && x != C + 1);
//	for (auto a : ret) printf("(%d,%d) ", a.first, a.second);
//	puts("");
	return ret;
}

bool is_valid(vector<pair<int, int> > p)
{
	auto fst = p[0], lst = p[p.size() - 1];
	return F[fst.first][fst.second] == F[lst.first][lst.second];
}

bool check_validity()
{
	for (int i = 1; i <= C; ++i) {
		if (!is_valid(trace_path(0, i, 1, 0))) return false;
		if (!is_valid(trace_path(R + 1, i, -1, 0))) return false;
	}
	for (int i = 1; i <= R; ++i) {
		if (!is_valid(trace_path(i, 0, 0, 1))) return false;
		if (!is_valid(trace_path(i, C + 1, 0, -1))) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;) {
		scanf("%d%d", &R, &C);

		for (int i = 0; i < (R + C); ++i) {
			scanf("%d%d", U + i, V + i);
			--U[i]; --V[i];
			idx[U[i]] = idx[V[i]] = i;
		}
		for (int i = 0; i < C; ++i) F[0][i + 1] = idx[i];
		for (int i = 0; i < R; ++i) F[i + 1][C + 1] = idx[i + C];
		for (int i = 0; i < C; ++i) F[R + 1][C - i] = idx[i + R + C];
		for (int i = 0; i < R; ++i) F[R - i][0] = idx[i + R + C + C];

		bool isok = false;
		for (int i = 0; i < (1 << (R * C)); ++i) {
			for (int j = 0; j < (R * C); ++j) {
				F[j / C + 1][j % C + 1] = (i >> j) & 1;
			}
			if (check_validity()) {
				isok = true;
				break;
			}
		}

		printf("Case #%d:\n", t);
		if (!isok) puts("IMPOSSIBLE");
		else {
			for (int i = 1; i <= R; ++i) {
				for (int j = 1; j <= C; ++j) {
					printf("%c", F[i][j] == 1 ? '\\' : '/');
				}
				puts("");
			}
		}
	}

	return 0;
}
