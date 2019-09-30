#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#undef HOME

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

int n, m, k, sq;
char matr[1024][1024];
char opt[1024][1024];

const int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d%d", &n, &m, &k);
		sq = n * m;

		for (int i = 0; i < n; i++) {
			memset(opt[i], '?', (m+1) * sizeof(opt[0][0]));
			opt[i][m] = 0;
		}

		int ans = k;
		int intrn = max(n-2, 0) * max(m-2, 0);

		for (int ttx = -1; ttx <= 1; ttx++)
			for (int tty = -1; tty <= 1; tty++) {

		for (int ins = 1; ins <= intrn; ins++) {

			for (int i = 0; i < n; i++) {
				memset(matr[i], '*', (m+1) * sizeof(matr[0][0]));
				matr[i][m] = 0;
			}

			int rem = ins;
			auto put = [&](int x, int y) -> void {
				if (rem <= 0) return;
				if (x < 1 || y < 1 || x >= n-1 || y >= m-1) return;
				rem--;
				matr[x][y] = '.';
			};
			int cx = n/2 + ttx;
			int cy = m/2 + tty;
			put(cx, cy);
			for (int rad = 1; rem > 0; rad++) {
				cx++;
				for (int t = 0; t < rad; t++) {
					cx--;  cy++;
					put(cx, cy);
				}
				for (int t = 0; t < rad; t++) {
					cx--;  cy--;
					put(cx, cy);
				}
				for (int t = 0; t < rad; t++) {
					cx++;  cy--;
					put(cx, cy);
				}
				for (int t = 0; t < rad; t++) {
					cx++;  cy++;
					put(cx, cy);
				}
			}

			for (int i = 1; i < n-1; i++)
				for (int j = 1; j < m-1; j++)
					if (matr[i][j] == '.') {
						for (int d = 0; d<4; d++) {
							int ni = i + dir[d][0];
							int nj = j + dir[d][1];
							if (matr[ni][nj] == '*')
								matr[ni][nj] = 'X';
						}
					}

			int ccnt = 0;
			int tres = sq;
			for (int i = 0; i<n; i++)
				for (int j = 0; j<m; j++) {
					if (matr[i][j] == '*')
						tres--;
					if (matr[i][j] == 'X')
						ccnt++;
				}
		
            Eo(ccnt);
            Eo(tres);
			for (int i = 0; i<n; i++)
				Ef("%s\n", matr[i]);
			Ef("\n");

			int add = max(k - tres, 0);
			tres += add;
			ccnt += add;
			assert(tres >= k);

			if (ans > ccnt) {
				ans = ccnt;
				memcpy(opt, matr, sizeof(matr));
			}
		}

		}

		printf("Case #%d: %d\n", tt, ans);
/*		for (int i = 0; i<n; i++)
			printf("%s\n", opt[i]);
		fflush(stdout);*/
	}
	return 0;
}
