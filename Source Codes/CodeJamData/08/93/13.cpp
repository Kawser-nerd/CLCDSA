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

const int MAXS = 5;

const int NEIGHBORS[9][2] = {
	{-1, -1},
	{-1, 0},
	{-1, 1},
	{0, -1},
	{0, 0},
	{0, 1},
	{1, -1},
	{1, 0},
	{1, 1}
};

int si, sj;
int aim[MAXS][MAXS];
int cur[MAXS][MAXS];
int num, ans;

inline void dfs(int i, int j) {
	if (j == sj) {
		j = 0;
		i++;
	}
	if (i == si) {
		bool isOk = true;
		for (int ci = 0; ci < si && isOk; ci++) {
			for (int cj = 0; cj < sj; cj++) {
				if (aim[ci][cj] != cur[ci][cj]) {
					isOk = false;
					break;
				}
			}
		}
		if (isOk) {
			ans = max(ans, num);
		}
	} else {
		bool isOk = true;
		for (int k = 0; k < 9; k++) {
			int ni = i + NEIGHBORS[k][0];
			int nj = j + NEIGHBORS[k][1];
			if (0 <= ni && ni < si && 0 <= nj && nj < sj) {
				if (++cur[ni][nj] > aim[ni][nj]) {
					isOk = false;
				}
			}
		}
		if (i + i + 1 == si) {
			num++;
		}
		if (isOk) {
			dfs(i, j + 1);
		}
		if (i + i + 1 == si) {
			num--;
		}
		for (int k = 0; k < 9; k++) {
			int ni = i + NEIGHBORS[k][0];
			int nj = j + NEIGHBORS[k][1];
			if (0 <= ni && ni < si && 0 <= nj && nj < sj) {
				--cur[ni][nj];
			}
		}
		dfs(i, j + 1);
	}
}

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		scanf("%d%d", &si, &sj);
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < sj; j++) {
				scanf("%d", &aim[i][j]);
			}
		}
		ans = -1;
		num = 0;
		dfs(0, 0);
		printf("Case #%d: %d\n", caseIndex, ans);
	}

	return 0;
}
