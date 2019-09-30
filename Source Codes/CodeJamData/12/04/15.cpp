#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
	#define D(x...) 0
#endif
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

char grid[50][50];
int tr, tc;
int H, W, D;

inline int gcd(int a, int b) {
	// PRECOND: a != 0 or b != 0; a,b > 0
	if (a < b) swap(a,b);
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

inline int nzsign(int d) {
	// PRECOND: d != 0
	return (d > 0) ? 1 : -1;
}

inline bool shootRay(int dr, int dc);

int main() {
	int nTests;
	scanf("%d ",&nTests);
	for (int test=1;test<=nTests;test++) {
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		scanf("%d%d%d ",&H,&W,&D);
		for (int i = 0; i < H; i++) scanf("%s ",grid[i]);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (grid[i][j] == 'X') {
					tr = i; tc = j;
				}
			}
		}

		int ans = 0;
		for (int dr = -D; dr <= D; dr++) {
		for (int dc = -D; dc <= D; dc++) {
			if (dr == 0 && dc == 0) continue;
			if (dr * dr + dc * dc > D * D) continue;
			if (gcd(abs(dr),abs(dc)) != 1) continue;
			if (shootRay(dr,dc)) ans++;
		}
		}
		
		printf("Case #%d: %d\n",test,ans);
	}
}

inline bool shootRay(int dr, int dc) {
	// PRECOND: dr, dc are rel. prime
	// returns whether successful move
	int cur_r = tr, cur_c = tc, cur_d_sq = 0;
	for (int nSteps = 1; ; nSteps++) {
		if ((dr * dr + dc * dc) * (nSteps * nSteps) > D * D) break;
		// move (dr,dc) from (cur_r, cur_c)
		int nMinisteps = (dr == 0 ? 1 : abs(dr)) * (dc == 0 ? 1 : abs(dc)) * 2;
		// (dr|dc) * [n mini]/nMinisteps = (j+1)/2
		// (j+1) = 2 * (dr|dc) * [n mini] / nMinisteps
		for (int k = 1; k < nMinisteps; k++) {
			// cur_r, cur_c -> approx current cell
			bool r_thing = ((2 * abs(dr) * k) % nMinisteps == 0) && (((2 * abs(dr) * k) / nMinisteps) % 2 == 1);
			bool c_thing = ((2 * abs(dc) * k) % nMinisteps == 0) && (((2 * abs(dc) * k) / nMinisteps) % 2 == 1);
			if (!r_thing && !c_thing) continue;
			if (r_thing && !c_thing) {
				// swap r direction
				if (grid[cur_r+nzsign(dr)][cur_c] == '#') {
					dr *= -1;
				} else {
					cur_r += nzsign(dr);
				}
			} else if (!r_thing && c_thing) {
				// swap c direction?
				if (grid[cur_r][cur_c+nzsign(dc)] == '#') {
					dc *= -1;
				} else {
					cur_c += nzsign(dc);
				}
			} else {
				assert(r_thing && c_thing);
				bool _r = (grid[cur_r+nzsign(dr)][cur_c] == '#');
				bool _c = (grid[cur_r][cur_c+nzsign(dc)] == '#');
				bool _rc = (grid[cur_r+nzsign(dr)][cur_c+nzsign(dc)] == '#');
				if (!_rc) {
					cur_r += nzsign(dr);
					cur_c += nzsign(dc);
				} else if (_r && _c) {
					dr *= -1;
					dc *= -1;
				} else if (_r) {
					dr *= -1;
					cur_c += nzsign(dc);
				} else if (_c) {
					cur_r += nzsign(dr);
					dc *= -1;
				} else {
					return false;
				}
			}
			//printf("dr,dc = %d,%d : %d/%d ministeps -> %d %d\n",dr,dc,k,nMinisteps,r_thing,c_thing);
		}
		if (cur_r == tr && cur_c == tc) return true;
	}
	return false;
}
