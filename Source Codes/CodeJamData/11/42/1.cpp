#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

int rows, cols;

struct Summatron {
	int t[505][505];
	int sum[505][505];

	int* operator[] (int x) {
		return t[x];
	}

	void init() {
		ZERO(sum);
		for (int i = 1; i <= rows; ++i)
			for (int j = 1; j <= cols; ++j) {
				sum[i][j] = t[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
	}

	int rectangleSum(int l, int r, int u, int d) {
		return sum[d][r] - sum[d][l - 1] - sum[u - 1][r] + sum[u - 1][l - 1];
	}

	int bladeSum(int l, int r, int u, int d) {
		return rectangleSum(l, r, u, d) - t[d][l] - t[d][r] - t[u][l] - t[u][r];
	}
};

Summatron classic, sumX, sumY;

void alg() {
	scanf("%d %d %*d", &rows, &cols);
	for (int i = 1; i <= rows; ++i) {
		for (int j = 1; j <= cols; ++j) {
			int value;
			scanf("%1d", &value);
			classic[i][j] = value;
			sumX[i][j] = j * value;
			sumY[i][j] = i * value;
		}
	}
	classic.init();
	sumX.init();
	sumY.init();
	bool got = false;
	for (int K = min(rows, cols); !got && K >= 3; --K) {
		for (int l = 1; !got && l + K - 1 <= cols; ++l) {
			for (int u = 1; !got && u + K - 1 <= rows; ++u) {
				int r = l + K - 1;
				int d = u + K - 1;
				int cSum = classic.bladeSum(l, r, u, d);
				if ((cSum * LL(K - 1)) % 2)
					continue;
				int cSumX = sumX.bladeSum(l, r, u, d) - (cSum * (2LL * l + LL(K) - 1)) / 2;
				int cSumY = sumY.bladeSum(l, r, u, d) - (cSum * (2LL * u + LL(K) - 1)) / 2;
				if (cSumX == 0 && cSumY == 0) {
					printf("%d\n", K);
					got = true;
				}
			}
		}
	}
	if (!got)
		printf("IMPOSSIBLE\n");
}

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		printf("Case #%d: ", testCase);
		alg();
	}
}
