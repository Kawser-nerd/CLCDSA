#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <numeric>

#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

int n;
char dat[2048][2048];

int countAns(vector<int> c)
{
	int best = INT_MAX;

	int cur = 0;
	for (int i = 0; i < c.size(); i++) {
		if (i % 2 && c[i]) {
			cur++;
		}
	}

	best = cur;

	cur = 0;
	for (int i = 0; i < c.size(); i++) {
		if (i % 2 && !c[i]) {
			cur++;
		}
	}

	best = min(best, cur);
	return best;
}

int main()
{
	int TT;
	scanf("%d", &TT);
	for (int testcase = 1; testcase <= TT; testcase++)
	{
		fprintf(stderr, "Processing case %d\n", testcase);
		scanf("%d", &n);
		for (int i = 0; i < 2 * n; i++) {
			scanf("%s", dat[i]);
			for (int j = 0; j < 2 * n; j++){
				dat[i][j] -= '0';
			}
		}

		bool imp = false;
		int cellCount = (2*n)*(2*n);
		map<vector<int>,int> rows;
		for (int i = 0; i < 2 * n; i++) {
			if (accumulate(dat[i], dat[i] + 2 * n, 0) != n) {
				imp = true;
				break;
			}
			int colcnt = 0;
			for (int j = 0; j < 2 * n; j++) {
				colcnt += dat[j][i];
			}
			if (colcnt != n) {
				imp = true;
				break;
			}
			vector<int> cur(dat[i], dat[i] + 2 * n);
			++rows[cur];
			if (rows.size() >= 3) {
				imp = true;
				break;
			}
		}

		if (rows.size() != 2) {
			imp = true;
		}

		if (!imp) {
			vector<int> v(2 * n);
			for (auto k : rows) {
				if (k.second != n) {
					imp = true;
					break;
				}
				for (int i = 0; i < 2 * n; i++) {
					v[i] += k.first[i];
				}
			}
			for (int i = 0; i < 2 * n; i++) {
				if (v[i] != 1) {
					imp = true;
					break;
				}
			}
		}


		if (imp) {
			printf("Case #%d: IMPOSSIBLE\n", testcase);
			continue;
		}

		vector<int> c;
		for (int i = 0; i < 2 * n; i++) {
			vector<int> cur(dat[i], dat[i] + 2 * n);
			if (cur == rows.begin()->first) {
				c.push_back(1);
			}
			else {
				c.push_back(0);
			}
		}

		int ans = countAns(rows.begin()->first) + countAns(c);

		printf("Case #%d: %d\n", testcase, ans);


		fprintf(stderr, "Finished case %d\n", testcase);
	}
}