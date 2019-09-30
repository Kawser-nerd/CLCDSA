#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <queue>
#include <utility>
#include <string.h>
#include <assert.h>
#include <string>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef complex<double> tComp;

const double EPS = 1e-9;
const int INF = 1000000000;

int nums[1002];
int lb[1002], rb[1002];
int n;
int memo[1002][2];

int doit(int left, int right, int mask) {
	int &res = memo[left][(mask >> nums[left]) & 1];
	if (res < INF)
		return res;
	res = 0;
	for (int i=left+1; i<right; ++i) {
		if (lb[i] != i || (((mask >> nums[left]) ^ (mask >> nums[i])) & 1))
			continue;
		if (rb[i] > right) {
			return res = INF - 1;
		}
		res = max(res, doit(lb[i], rb[i], mask));
	}
	if (res < INF)
		++res;
	assert(res >= 0);
	return res;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("usage: %s <input_file>\n", argv[0]);
		return 1;
	}
	freopen(argv[1], "r", stdin);
	int tc;
	cin >> tc;
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d: ", scen);
		map<string, int> tonums;
		string col;
		cin >> n;
		n *= 2;
		for (int i=0; i<n; ++i) {
			cin >> col;
			if (tonums.find(col) == tonums.end()) {
				int t = tonums.size();
				tonums[col] = t;
				nums[i] = t;
			}
			else {
				nums[i] = tonums[col];
				bool found = false;
				for (int j=0; j<i; ++j)
					if (nums[j] == nums[i]) {
						rb[j] = rb[i] = i;
						lb[j] = lb[i] = j;
						found = true;
						break;
					}
				assert(found);
			}
		}
		int res = INF;
		for (int m=1<<(n/2); m--; ) {
			int mint = 0, maxt = 0;
			for (int i=0; i<n; ++i)
				memo[i][0] = memo[i][1] = INF;
			int cnt = 0;
			for (int i=0; i<n; ++i) {
				if (lb[i] == i) {
					++cnt;
					int t = doit(lb[i], rb[i], m);
					if (m & (1 << nums[i]))
						maxt = max(maxt, t);
					else
						mint = max(mint, t);
				}
			}
			assert(cnt > 0 && (maxt > 0 || mint > 0));
			if (mint < INF && maxt < INF)
				res = min(res, mint + maxt);
		}
		if (res >= INF-1)
			puts("-1");
		else {
			assert(res > 0 && res < INF);
			printf("%d\n", res);
		}
		fflush(stdout);
	}
	return 0;
}
