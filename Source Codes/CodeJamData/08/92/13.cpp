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

const int MAXS = 100;

typedef pair<int, int> PII;

bool tags[MAXS][MAXS];
PII bfs[MAXS * MAXS];

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int si, sj;
		scanf("%d%d", &si, &sj);
		int moves[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				scanf("%d", &moves[i][j]);
			}
		}
		int bi, bj;
		scanf("%d%d", &bi, &bj);
		for (int i = 0; i < si; i++) {
			memset(tags[i], false, sizeof(bool) * sj);
		}
		tags[bi][bj] = true;
		bfs[0] = PII(bi, bj);
		int begin = 0, end = 1;
		while (begin < end) {
			PII p = bfs[begin++];
			for (int k = 0; k < 2; k++) {
				int ni = p.first + moves[k][0];
				int nj = p.second + moves[k][1];
				if (0 <= ni && ni < si && 0 <= nj && nj < sj && !tags[ni][nj]) {
					tags[ni][nj] = true;
					bfs[end++] = PII(ni, nj);
				}
			}
		}
		printf("Case #%d: %d\n", caseIndex, end);
	}

	return 0;
}
