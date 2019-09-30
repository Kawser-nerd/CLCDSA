// Adrian Kügel
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <complex>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;

typedef set<int> SI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef complex<double> tComp;
typedef pair<int, int> PII;

char grid[20][21];
int n, m;
int dirs[4][2] = {{-1, 0},{0, -1}, {1, 0},{0, 1}};


struct state {
	unsigned char bits[19];
};

void set_bit(state &a, int b) {
	a.bits[b >> 3] |= (1 << (b & 7));
}

int get_bit(const state &a, int b) {
	return a.bits[b >> 3] & (1 << (b & 7));
}

void unset_bit(state &a, int b) {
	if (get_bit(a, b))
		a.bits[b >> 3] ^= (1 << (b & 7));
}

bool operator<(const state &a, const state &b) {
	return memcmp(a.bits, b.bits, 19) < 0;
}

int cnt_reach(state &mask, int x, int y) {
	if (get_bit(mask, x * m + y) == 0)
		return 0;
	int ret = 1;
	unset_bit(mask, x * m + y);
	for (int d=0; d<4; ++d) {
		int tx = dirs[d][0] + x;
		int ty = dirs[d][1] + y;
		if (tx >= 0 && tx < n && ty >= 0 && ty < m)
			ret += cnt_reach(mask, tx, ty);
	}
	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d: ", scen);
		scanf("%d %d", &n, &m);
		set<state> visit;
		state wall_mask, wanted_mask, have_mask;
		memset(wall_mask.bits, 0, 19);
		memset(wanted_mask.bits, 0, 19);
		memset(have_mask.bits, 0, 19);
		int k = 0, k2 = 0;
		for (int i=0; i<n; ++i) {
			scanf("%s", grid[i]);
			for (int j=0; j<m; ++j) {
				if (grid[i][j] == 'w') {
					set_bit(wanted_mask, i*m + j);
					set_bit(have_mask, i*m + j);
					++k;
					++k2;
				}
				else if (grid[i][j] == 'x') {
					set_bit(wanted_mask, i * m + j);
					++k2;
				}
				else if (grid[i][j] == 'o') {
					set_bit(have_mask, i * m + j);
					++k;
				}
				else if (grid[i][j] == '#') {
					set_bit(wall_mask, i * m + j);
				}
				else
					assert(grid[i][j] == '.');
			}
		}
		assert(k == k2);
		queue<state> Q;
		Q.push(have_mask);
		visit.insert(have_mask);
		int dist = 0;
		while(!Q.empty()) {
			int qsize = Q.size();
			while(qsize--) {
				state cur = Q.front();
				if (!memcmp(cur.bits, wanted_mask.bits, 19)) {
					printf("%d\n", dist);
					goto done;
				}
				Q.pop();
				int c = 0;
				for (int i=0; i<n; ++i)
					for (int j=0; j<m; ++j) {
						if (get_bit(cur, i * m + j)) {
							++c;
							for (int d=0; d<4; ++d) {
								int fx = i - dirs[d][0];
								int fy = j - dirs[d][1];
								if (fx < 0 || fx >= n || fy < 0 || fy >= m || get_bit(wall_mask, fx * m + fy) || get_bit(cur, fx * m + fy))
									continue;
								int tx = i + dirs[d][0];
								int ty = j + dirs[d][1];
								if (tx < 0 || tx >= n || ty < 0 || ty >= m || get_bit(wall_mask, tx * m + ty) || get_bit(cur, tx * m + ty))
									continue;
								state nmask = cur;
								unset_bit(nmask, i*m + j);
								set_bit(nmask, tx*m+ty);
								state tmask = nmask;
								if (cnt_reach(tmask, tx, ty) < k) {
									if (get_bit(nmask, n*m))
										continue;
									set_bit(nmask, n * m);
								}
								else if (get_bit(nmask, n*m)) {
									unset_bit(nmask, n * m);
								}
								if (visit.find(nmask) == visit.end()) {
									visit.insert(nmask);
									Q.push(nmask);
								}
							}
						}
					}
			}
			++dist;
		}
		puts("-1");
		continue;
done:;
	}
	return 0;
}
