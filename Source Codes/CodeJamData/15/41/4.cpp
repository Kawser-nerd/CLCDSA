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
char in[120][120];

int dy[] = { -1, 0, 1, 0 }, dx[] = { 0, -1, 0, 1 };

int to_d(char c)
{
	if (c == '^') return 0;
	if (c == '<') return 1;
	if (c == 'v') return 2;
	return 3;
}

bool hit(int y, int x, int d)
{
	y += dy[d];
	x += dx[d];

	for (;;) {
		if (y < 0 || x < 0 || R <= y || C <= x) return false;
		if (in[y][x] != '.') return true;
		y += dy[d];
		x += dx[d];
	}
	return false;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; ++i) scanf("%s", in[i]);

		int ret = 0;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (in[i][j] == '.') continue;

				int good = 100000;
				for (int k = 0; k < 4; ++k) {
					if (hit(i, j, k)) {
						if (to_d(in[i][j]) == k) {
							good = 0;
							break;
						} else good = 1;
					}
				}

				if (good == 100000) ret = 100000;
				else ret += good;
			}
		}

		if (ret > R * C) {
			printf("Case #%d: IMPOSSIBLE\n", t);
		} else {
			printf("Case #%d: %d\n", t, ret);
		}
	}

	return 0;
}
