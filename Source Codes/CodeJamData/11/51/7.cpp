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

typedef long double LD;

LD areaTo(vector<PII> line, LD xr) {
	LD result = 0;
	for (int i = 0; i + 1 < (int) line.size(); ++i) {
		if (line[i].ST >= xr)
			return result;
		LD cxl = line[i].ST;
		LD cyl = line[i].ND;
		LD cxr, cyr;
		if (line[i + 1].ST >= xr) {
			cxr = xr;
			cyr = cyl + (line[i + 1].ND - cyl) * (cxr - cxl) / (line[i + 1].ST - cxl);
		} else {
			cxr = line[i + 1].ST;
			cyr = line[i + 1].ND;
		}
		result += (cyr + cyl) * (cxr - cxl) / 2;
	}
	return result;
}

vector<PII> readPolyline(int n) {
	vector<PII> ret;
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		y += 1005;
		ret.PB(MP(x, y));
	}
	return ret;
}

void alg() {
	int width, nUpper, nLower, g;
	scanf("%d %d %d %d", &width, &nLower, &nUpper, &g);
	vector<PII> upper, lower;
	lower = readPolyline(nLower);
	upper = readPolyline(nUpper);
	LD totalArea = areaTo(upper, width) - areaTo(lower, width);
	for (int i = 1; i < g; ++i) {
		LD required = totalArea * i / g;
		LD l = 0, r = width;
		for (int j = 0; j < 100; ++j) {
			LD c = (l + r) / 2;
			LD score = areaTo(upper, c) - areaTo(lower, c);
			if (score > required)
				r = c;
			else
				l = c;
		}
		printf("%.9Lf\n", (l + r) / 2.0);
	}
}

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		printf("Case #%d:\n", testCase);
		alg();
	}
}
