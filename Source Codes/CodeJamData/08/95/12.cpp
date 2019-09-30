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

const int MAXS = 15;

int cnts[1 << MAXS];
int dp[2][1 << MAXS];
int valid[1 << MAXS];

int main() {
	for (int mask = 0; mask < (1 << MAXS); mask++) {
		cnts[mask] = 0;
		for (int i = 0; i < MAXS; i++) {
			if (mask & (1 << i)) {
				cnts[mask]++;
			}
		}
	}
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int si, sj;
		scanf("%d%d", &si, &sj);
		int needs[MAXS], bans[MAXS];
		char str[MAXS + 1];
		gets(str);
		if (si >= sj) {
			for (int i = 0; i < si; i++) {
				needs[i] = bans[i] = 0;
				gets(str);
				for (int j = 0; j < sj; j++) {
					switch (str[j]) {
						case '#': 
							needs[i] |= (1 << j);
							break;
						case '.':
							bans[i] |= (1 << j);
							break;
					}
				}
			}
		} else {
			for (int j = 0; j < sj; j++) {
				needs[j] = bans[j] = 0;
			}
			for (int i = 0; i < si; i++) {
				gets(str);
				for (int j = 0; j < sj; j++) {
					switch (str[j]) {
						case '#': 
							needs[j] |= (1 << i);
							break;
						case '.':
							bans[j] |= (1 << i);
							break;
					}
				}
			}
			swap(si, sj);
		}
		const int size = 1 << sj;
		memset(dp[0], 0xff, sizeof(int) * size);
		dp[0][0] = 0;
		int cur = 0;
		for (int i = 0; i < si; i++) {
			int next = !cur;
			memset(dp[next], 0xff, sizeof(int) * size);
			int vnum = 0;
			for (int mask = 0; mask < size; mask++) {
				if ((mask & needs[i]) == needs[i] && (mask & bans[i]) == 0) {
					valid[vnum++] = mask;
				}
			}
			for (int mask = 0; mask < size; mask++) {
				if (dp[cur][mask] >= 0) {
					for (int v = 0; v < vnum; v++) {
						int nm = valid[v];
						dp[next][nm] = max(dp[next][nm], dp[cur][mask] + (cnts[nm] << 2) - (cnts[nm & mask] << 1) - (cnts[nm & (nm >> 1)] << 1));
					}
				}
			}
			cur = next;
		}
		int ans = 0;
		for (int mask = 0; mask < size; mask++) {
			ans = max(ans, dp[cur][mask]);
		}

		printf("Case #%d: %d\n", caseIndex, ans);
	}

	return 0;
}
