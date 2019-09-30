#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 8;

int n, m;

int ind[MAXN];
bool adja[MAXN][MAXN];
bool adjb[MAXN][MAXN];
bool adjc[MAXN][MAXN];

bool generate(int i) {
	if (i == m) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (adjb[i][j] && !adjc[i][j]) {
					return false;
				}
			}
		}
		return true;
	} else {
		for (int j = 0; j < n; j++) {
			if (ind[j] == -1) {
				ind[j] = i;
				for (int k = 0; k < n; k++) {
					if (adja[j][k] && ind[k] >= 0) {
						adjc[i][ind[k]] = adjc[ind[k]][i] = true;
					}
				}
				if (generate(i + 1)) {
					return true;
				}
				for (int k = 0; k < i; k++) {
					adjc[i][k] = adjc[k][i] = false;
				}
				ind[j] = -1;
			}
		}
		return false;
	}
}

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		scanf("%d", &n);
		memset(adja, false, sizeof(adja));
		for (int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			adja[a][b] = adja[b][a] = true;
		}
		scanf("%d", &m);
		memset(adjb, false, sizeof(adjb));
		for (int i = 1; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			adjb[a][b] = adjb[b][a] = true;
		}
		printf("Case #%d: ", caseIndex);
		memset(ind, 0xff, sizeof(ind));
		memset(adjc, false ,sizeof(adjc));
		if (generate(0)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}

	return 0;
}
