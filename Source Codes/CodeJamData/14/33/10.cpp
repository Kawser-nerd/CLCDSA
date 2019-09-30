#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int f[1001][31][31], g[1001][31][31];

template<class T> bool checkMin(T &a, const T &b) {
	return b < a ? a = b, true : false;
}

int main() {
	int nTest; cin >> nTest;
	for(int test = 0; test < nTest; ++test) {
		cerr << "RUNNING ON " << test << endl;
		int m, n, k; cin >> m >> n >> k;
		if(m < n) swap(m, n);
		int res = k;
		memset(f, 0x3f, sizeof f);
		for(int x = 0; x < n; ++x)
			for(int y = x; y < n; ++y)
				f[y - x + 1][x][y] = y - x + 1;
		for(int row = 0; row < m - 1; ++row) {
			memset(g, 0x3f, sizeof g);
			for(int c = 0; c <= m * n; ++c)
				for(int x = 0; x < n; ++x)
					for(int y = x; y < n; ++y)
						for(int xx = max(0, x - 1); xx <= min(n - 1, x + 1); ++xx)
							for(int yy = max(0, y - 1); yy <= min(n - 1, y + 1); ++yy)
								if(xx <= yy) checkMin(g[c + (yy - xx + 1)][xx][yy], f[c][x][y] + (xx == yy ? 1 : 2));
			memcpy(f, g, sizeof f);
			for(int c = k; c <= m * n; ++c)
				for(int x = 0; x < n; ++x)
					for(int y = x; y < n; ++y)
						checkMin(res, f[c][x][y] + max(0, y - x - 1));
		}
		printf("Case #%d: %d\n", test + 1, res);
	}
	return 0;
}
