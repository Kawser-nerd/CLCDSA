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

int hash(int y, int x) {
	return (y - 1) * cols + x;
}

const int N = 10005;

int p[N];
int nVertices[N], nEdges[N];

int gp(int x) {
	if (p[x] != x)
		p[x] = gp(p[x]);
	return p[x];
}

void addEdge(int u, int v) {
	u = gp(u);
	v = gp(v);
	if (u != v) {
		nVertices[u] += nVertices[v];
		nEdges[u] += nEdges[v];
		p[v] = u;
	}
	++nEdges[u];
}

char buf[N];

const int MD = 1000003;

void alg() {
	scanf("%d %d", &rows, &cols);
	int n = rows * cols;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		nVertices[i] = 1;
		nEdges[i] = 0;
	}
	for (int i = 1; i <= rows; ++i) {
		scanf("%s", buf + 1);
		for (int j = 1; j <= cols; ++j) {
			if (buf[j] == '-') {
				int y = i;
				int x1 = (j + cols - 2) % cols + 1;
				int x2 = j % cols + 1;
				addEdge(hash(y, x1), hash(y, x2));
			} else if (buf[j] == '|') {
				int x = j;
				int y1 = (i + rows - 2) % rows + 1;
				int y2 = i % rows + 1;
				addEdge(hash(y1, x), hash(y2, x));
			} else if (buf[j] == '/') {
				int y1 = (i + rows - 2) % rows + 1;
				int x1 = j % cols + 1;
				int y2 = i % rows + 1;
				int x2 = (j + cols - 2) % cols + 1;
				addEdge(hash(y1, x1), hash(y2, x2));
			} else {
				int y1 = (i + rows - 2) % rows + 1;
				int x1 = (j + cols - 2) % cols + 1;
				int y2 = i % rows + 1;
				int x2 = j % cols + 1;
				addEdge(hash(y1, x1), hash(y2, x2));
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (p[i] == i) {
			if (nVertices[i] != nEdges[i]) {
				printf("0\n");
				return;
			}
			++cnt;
		}
	LL result = 1;
	for (int i = 0; i < cnt; ++i)
		result = (result * 2) % MD;
	printf("%lld\n", result);
}

int main() {
	int d;
	scanf("%d", &d);
	for (int testCase = 1; testCase <= d; ++testCase) {
		printf("Case #%d: ", testCase);
		alg();
	}
}
