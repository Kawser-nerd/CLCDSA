#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

struct frac
{
	i64 x, y;
	frac(i64 x, i64 y) : x(x), y(y) {}
};

inline bool operator<(const frac& a, const frac& b)
{
	return a.y * b.x < a.x * b.y;
}

int T;
int N, Xi[3010], Yi[3010];

int solve(int p)
{
	int ret = N;
	vector<pair<frac, int> > pts;

	int lf = 0, rg = 0;
	for (int i = 0; i < N; ++i) {
		int dx = Xi[i] - Xi[p], dy = Yi[i] - Yi[p];
		if (i == p) continue;
		if (dx > 0) {
			++rg;
			pts.push_back(make_pair(frac(dx, dy), -2));
			pts.push_back(make_pair(frac(dx, dy), 1));
		} else if (dx < 0) {
			++lf;
			pts.push_back(make_pair(frac(-dx, -dy), -1));
			pts.push_back(make_pair(frac(-dx, -dy), 2));
		} else {
			if (dy > 0) pts.push_back(make_pair(frac(0, -1), 2));
			else pts.push_back(make_pair(frac(0, -1), 1));
		}
	}

	ret = min(lf, rg);
	sort(pts.begin(), pts.end());

	for (auto t : pts) {
		if (t.second == -1) --lf;
		if (t.second == -2) --rg;
		if (t.second == 1) ++lf;
		if (t.second == 2) ++rg;

//		printf("%d: %d %d\n", p, lf, rg);
		ret = min(ret, min(lf, rg));
	}

	return ret;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d%d", Xi + i, Yi + i);

		printf("Case #%d:\n", t);
		for (int i = 0; i < N; ++i) {
			printf("%d\n", solve(i));
		}
	}

	return 0;
}
