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

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 64;

int n, m;
char matr[SIZE][SIZE];

struct State {
	static const int SZ = 10;
	int mask[SZ];

	inline void Clear() { memset(mask, 0, sizeof(mask)); }
	inline bool operator< (const State &oth) const {
		for (int i = 0; i<n; i++)
			if (mask[i] != oth.mask[i])
				return mask[i] < oth.mask[i];
		return false;			
	}
	inline bool operator== (const State &oth) const {
		for (int i = 0; i<n; i++)
			if (mask[i] != oth.mask[i])
				return false;
		return true;	
	}
};

const int dir[3][2] = {{0,1}, {0,-1}, {1,0}};

bool vis[SIZE][SIZE];
void Solve(int sx, int sy, int &scnt, bool &islucky) {
	memset(vis, 0, sizeof(vis));
	vis[sx][sy] = true;

	for (int t = 0; t<SIZE; t++) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++)
				if (vis[i][j] && matr[i][j+1] != '#') vis[i][j+1] = true;
			for (int j = m-1; j>=0; j--)
				if (vis[i][j] && matr[i][j-1] != '#') vis[i][j-1] = true;
		}
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				if (vis[i][j] && matr[i-1][j] != '#') vis[i-1][j] = true;
	}

	State ss, want;
	want.Clear();
	want.mask[sx] = 1<<sy;
	ss.Clear();
	scnt = 0;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++) if (vis[i][j]) {
			scnt++;
			ss.mask[i] ^= (1<<j);
		}    

	islucky = (ss == want);
	vector<State> qarr;
	set<State> used;
	qarr.push_back(ss);
	used.insert(ss);
    for (int i = 0; i<qarr.size(); i++) {
		State curr = qarr[i];

		for (int d = 0; d<3; d++) {
			int dx = dir[d][0];
			int dy = dir[d][1];

			State next;
			next.Clear();

			bool badmove = false;
			for (int i = 0; !badmove && i<n; i++)
				for (int j = 0; j<m; j++) if ((curr.mask[i] >> j) & 1){
					int ni = i + dx;
					int nj = j + dy;
					if (matr[ni][nj] == '#') {
						ni = i;
						nj = j;
					}
					if (!vis[ni][nj]) {
						badmove = true;
						break;
					}
					next.mask[ni] |= (1<<nj);
				}
			
			if (badmove) continue;

			if (used.find(next) != used.end()) continue;
			qarr.push_back(next);
			used.insert(next);
			if (next == want) {
				islucky = true;
				return;
			}
		}
    }
}


int starts[16];
bool lucky[16];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i<n; i++)
			scanf("%s", matr[i]);

		int k = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++) if (matr[i][j] >= '0' && matr[i][j] <= '9') {
				int q = matr[i][j] - '0';
				Solve(i, j, starts[q], lucky[q]);
				k = max(k, q);
			}
		k++;

		printf("Case #%d:\n", tt);
		for (int i = 0; i<k; i++) {
			printf("%d: %d %s\n", i, starts[i], (lucky[i] ? "Lucky" : "Unlucky"));
		}
		fflush(stdout);
	}
	return 0;
}
