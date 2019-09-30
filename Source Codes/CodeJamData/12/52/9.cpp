#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxS = 6050;
const int maxM = 11000;

int S, m;
char board[maxS][maxS];
char isIn[maxS][maxS];
int used[maxS][maxS];

string ans[8] = {
	"none",
	"ring",
	"bridge",
	"bridge-ring",
	"fork",
	"fork-ring",
	"bridge-fork",
	"bridge-fork-ring"
};

void getIsIn() {
	memset(isIn, 0, sizeof(isIn));
	for (int i = 1; i <= S; ++i) {
		isIn[i][i] = 1;
		for (int j = 1; j < S; ++j) {
			isIn[i + j][i] = 1;
			isIn[i][i + j] = 1;
		}
	}

	for (int i = 1; i < S; ++i) {
		isIn[S + i][S + i] = 1;
		for (int j = 1; j < S - i; ++j) {
			isIn[S + i + j][S + i] = isIn[S + i][S + i + j] = 1;
		}
	}
}

int dx[] = {1, 0, -1, -1, 0, 1};
int dy[] = {1, 1, 0, -1, -1, 0};

vector < pair < int, int > > cells;

int is_in(int x, int y) {
	if (x >= 0 && y >= 0 && isIn[x][y]) return 1;
	return 0;
}

void dfs(int x, int y, int value) {
	if (used[x][y]) return;
	used[x][y] = value;

	for (int i = 0; i < 6; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (is_in(cx, cy)) {
			if (board[cx][cy] == board[x][y]) {
				dfs(cx, cy, value);
			}
		}
	}
}

vector < int > neg;

void updateComponents() {
	int t = 1;
	for (int i = 0; i < cells.size(); ++i) {
		int x = cells[i].first;
		int y = cells[i].second;
		if (!used[x][y]) {
			dfs(x, y, t);
			++t;
		}
	}
}

int checkRing() {
	for (int i = 0; i < cells.size(); ++i) {
		used[cells[i].first][cells[i].second] = 0;
	}
	int x = cells.back().first, y = cells.back().second;
	board[x][y] = 0;
	cells.pop_back();
	updateComponents();
	board[x][y] = 1;

	int col[6];
	memset(col, 0, sizeof(col));
	for (int i = 0; i < 6; ++i) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (!is_in(cx, cy)) {
			col[i] = -1;
		} else {
			col[i] = used[cx][cy];
		}
	}

	cells.push_back(make_pair(x, y));
	for (int i = 0; i < 6; ++i) {
		for (int j = i + 1; j < 6; ++j) {
			if (col[i] != -1 && col[j] != -1 && col[i] == col[j] && col[i] != 0) {
				int check1 = 0;
				for (int k = i; k <= j; ++k) {
					if (col[k] != col[i]) check1 = 1;
				}

				int check2 = 0;
				for (int k = j; k < 6; ++k) {
					if (col[k] != col[i]) check2 = 1;
				}
				for (int k = 0; k <= i; ++k) {
					if (col[k] != col[i]) check2 = 1;
				}

				if (!(check1 == 0 || check2 == 0)) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int checkBridge() {
	set < int > cur;
	vector < pair < int, int > > corners;
	corners.push_back(make_pair(1, 1));
	corners.push_back(make_pair(2 * S - 1, 2 * S - 1));
	corners.push_back(make_pair(1, S));
	corners.push_back(make_pair(S, 1));
	corners.push_back(make_pair(2 * S - 1, S));
	corners.push_back(make_pair(S, 2 * S - 1));

	for (int i = 0; i < 6; ++i) {
		int x = corners[i].first;
		int y = corners[i].second;
		if (used[x][y] > 0) {
			if (cur.count(used[x][y])) return 1;
			cur.insert(used[x][y]);
		}
	}
	return 0;
}

int usedE[maxM];

int checkFork() {
	memset(usedE, 0, sizeof(usedE));
	set < int > edges[6];
	for (int i = 2; i < S; ++i) {
		if (used[1][i] > 0) usedE[used[1][i]] |= 1;
		if (used[i][1] > 0) usedE[used[i][1]] |= 2;
	}

	for (int i = 2; i < S; ++i) {
		if (used[S - 1 + i][i] > 0) usedE[used[S - 1 + i][i]] |= 4;
		if (used[i][S - 1 + i] > 0) usedE[used[i][S - 1 + i]] |= 8;
	}

	for (int i = 2; i < S; ++i) {
		if (used[2 * S - 1][2 * S - i] > 0) usedE[used[2 * S - 1][2 * S - i]] |= 16;
		if (used[2 * S - i][2 * S - 1] > 0) usedE[used[2 * S - i][2 * S - 1]] |= 32;
	}

	for (int i = 1; i < maxM; ++i) {
		bitset <6> b = usedE[i];
		if (b.count() >= 3) return 1;
	}
	return 0;

	map < int, int > mp;
	for (int i = 0; i < 6; ++i) {
		for (set < int > :: iterator it = edges[i].begin(); it != edges[i].end(); ++it) {
			++mp[*it];
		}
	}

	for (map < int, int > :: iterator it = mp.begin(); it != mp.end(); ++it) {
		int x = it->first;
		int y = it->second;
		if (x > 0 && y >= 3) return 1;
	}
	return 0;
}

void solve(int test) {
	cells.clear();
	memset(board, 0, sizeof(board));
	printf("Case #%d: ", test);
	scanf("%d%d", &S, &m);

	getIsIn();

	int ok = 0;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		board[x][y] = 1;
		cells.push_back(make_pair(x, y));
		updateComponents();
		int res = 0;
		res += checkBridge() * 2;
		res += checkFork() * 4;
		res += checkRing();

		if (res != 0 && !ok) {
			cout << ans[res];
			printf(" in move %d\n", i);
			ok = 1;
		}

		for (int j = 0; j < cells.size(); ++j) {
			used[cells[j].first][cells[j].second] = 0;
		}
	}
	if (!ok) printf("none\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << i << endl;
	}
	return 0;
}