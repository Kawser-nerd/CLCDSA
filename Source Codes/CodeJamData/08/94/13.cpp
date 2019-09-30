#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define ASSERT(x) if (!(x)) printf("Wrong assert at line %d\n", __LINE__)

const int MAXS = 30;
const int INF = 0x7f7f7f7f;

const int MOVES[4][2] = {
	{0, -1},
	{0, 1},
	{-1, 0},
	{1, 0}
};

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

int si, sj;
int minDis[MAXS][MAXS];
int disSum[MAXS][MAXS];
bool tags[MAXS][MAXS];
char grids[MAXS][MAXS + 1];
PII bfs[MAXS * MAXS];
PII forests[MAXS * MAXS];
int fnum, ans;

void addForest(int f) {
	int i = forests[f].first;
	int j = forests[f].second;
	ans += disSum[i][j];
	while (!tags[i][j]) {
		tags[i][j] = true;
		for (int k = 0; ; k++) {
			ASSERT(k < 4);
			int ni = i + MOVES[k][0];
			int nj = j + MOVES[k][1];
			if (0 <= ni && ni < si && 0 <= nj && nj < sj && grids[ni][nj] != '.' && minDis[ni][nj] == minDis[i][j] - 1 && disSum[ni][nj] == disSum[i][j] - minDis[i][j]) {
				i = ni;
				j = nj;
				break;
			}
		}
	}
}

void updateGraph() {
	int begin = 0, end = 0;
	for (int i = 0; i < si; i++) {
		memset(minDis[i], 0xff, sizeof(int) * sj);
		memset(disSum[i], 0x7f, sizeof(int) * sj);
	}
	for (int i = 0; i < fnum; i++) {
		if (tags[forests[i].first][forests[i].second]) {
			minDis[forests[i].first][forests[i].second] = disSum[forests[i].first][forests[i].second] = 0;
			bfs[end++] = forests[i];
		}
	}
	while (begin < end) {
		const PII & p = bfs[begin++];
		for (int k = 0; k < 4; k++) {
			int ni = p.first + MOVES[k][0];
			int nj = p.second + MOVES[k][1];
			if (0 <= ni && ni < si && 0 <= nj && nj < sj && grids[ni][nj] != '.') {
				if (minDis[ni][nj] == -1) {
					minDis[ni][nj] = minDis[p.first][p.second] + 1;
					disSum[ni][nj] = disSum[p.first][p.second] + (tags[ni][nj] ? 0 : minDis[ni][nj]);
					bfs[end++] = PII(ni, nj);
				} else if (minDis[ni][nj] == minDis[p.first][p.second] + 1) {
					disSum[ni][nj] = min(disSum[ni][nj], disSum[p.first][p.second] + (tags[ni][nj] ? 0 : minDis[ni][nj]));
				}
			}
		}
	}
}

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		scanf("%d%d", &si, &sj);
		while (getchar() != '\n');
		for (int i = 0; i < si; i++) {
			gets(grids[i]);
			memset(tags[i], false, sizeof(bool) * sj);
			memset(minDis[i], 0xff, sizeof(int) * sj);
		}
		fnum = 0;
		ans = 0;
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < sj; j++) {
				if (grids[i][j] == 'T') {
					forests[fnum++] = PII(i, j);
				}
			}
		}
		tags[0][0] = true;
		minDis[0][0] = 0;
		disSum[0][0] = 0;
		bfs[0] = PII(0, 0);
		int begin = 0, end = 1;
		while (begin < end) {
			const PII & p = bfs[begin++];
			for (int k = 0; k < 4; k++) {
				int ni = p.first + MOVES[k][0];
				int nj = p.second + MOVES[k][1];
				if (0 <= ni && ni < si && 0 <= nj && nj < sj && grids[ni][nj] != '.' && minDis[ni][nj] == -1) {
					minDis[ni][nj] = minDis[p.first][p.second] + 1;
					disSum[ni][nj] = disSum[p.first][p.second] + minDis[ni][nj];
					bfs[end++] = PII(ni, nj);
				}
			}
		}
		if (fnum == 1) {
			ans = 0;
			for (int i = 0; i < si; i++) {
				for (int j = 0; j < sj; j++) {
					if (grids[i][j] != '.') {
						ans += minDis[i][j];
					}
				}
			}
		} else {
			for (int fget = 1; fget < fnum; fget++) {
				int nf = -1;
				for (int i = 1; i < fnum; i++) {
					if (!tags[forests[i].first][forests[i].second] && (nf == -1 || minDis[forests[i].first][forests[i].second] < minDis[forests[nf].first][forests[nf].second])) {
						nf = i;
					}
				}
				addForest(nf);
				updateGraph();
			}
			for (int i = 0; i < si; i++) {
				memset(minDis[i], 0x7f, sizeof(int) * sj);
			}
			begin = 0;
			for (end = 0; end < fnum; end++) {
				minDis[forests[end].first][forests[end].second] = 0;
				bfs[end] = forests[end];
			}
			priority_queue<PIII, vector<PIII>, greater<PIII> > heap;
			while (begin < end) {
				const PII & p = bfs[begin++];
				for (int k = 0; k < 4; k++) {
					int ni = p.first + MOVES[k][0];
					int nj = p.second + MOVES[k][1];
					if (0 <= ni && ni < si && 0 <= nj && nj < sj && grids[ni][nj] == '#') {
						if (tags[ni][nj]) {
							if (minDis[ni][nj] == INF) {
								minDis[ni][nj] = minDis[p.first][p.second] + 1;
								bfs[end++] = PII(ni, nj);
							}
						} else {
							if (minDis[ni][nj] > minDis[p.first][p.second] + 1) {
								minDis[ni][nj] = minDis[p.first][p.second] + 1;
								heap.push(PIII(minDis[ni][nj], PII(ni, nj)));
							}
						}
					}
				}
			}
			while (!heap.empty()) {
				const PIII p = heap.top();
				heap.pop();
				const PII & pos = p.second;
				if (!tags[pos.first][pos.second]) {
					ASSERT(minDis[pos.first][pos.second] == p.first);
					tags[pos.first][pos.second] = true;
					ans += p.first;
					for (int k = 0; k < 4; k++) {
						int ni = pos.first + MOVES[k][0];
						int nj = pos.second + MOVES[k][1];
						if (0 <= ni && ni < si && 0 <= nj && nj < sj && grids[ni][nj] == '#' && !tags[ni][nj] && minDis[ni][nj] > p.first + 1) {
							minDis[ni][nj] = p.first + 1;
							heap.push(PIII(minDis[ni][nj], PII(ni, nj)));
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", caseIndex, ans);
	}

	return 0;
}
