#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

bool seekEoln() {
	int ch;
	for (;;) {
		ch = getc(stdin);
		if (ch != ' ')
			break;
	}
	ungetc(ch, stdin);
	return ch == '\r' || ch == '\n' || ch == -1;
}

#ifndef _DEBUG
#define assert(f) if (!(f)) printf("\n%s\n", "ASSERTION FAILED!");
#endif

char buf[1024*1024];

int rd() {
	int x;
	bool f = scanf("%d", &x) == 1;
	assert(f);
	return x;
}

double rlf() {
	double x;
	bool f = scanf("%lf", &x) == 1;
	assert(f);
	return x;
}

string rs() {
	bool f = scanf("%s", buf) == 1;
	assert(f);
	return buf;
}

vi rvi() {
	int n;
	bool f = scanf("%d", &n) == 1;
	assert(f);
	vi x(n);
	Rep(i, n) {
		f = scanf("%d", &x[i]) == 1;
		assert(f);
	}
	return x;
}

void print(const vi& v) {
	Rep(i, Size(v)) {
		if (i > 0)
			printf(" ");
		printf("%d", v[i]);
	}
	printf("\n");
}

int m, n;
char a[10][11];
int row[10];
int dp[10][1<<10];
int cbits[1<<10];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	For(i, 1, (1<<10)-1)
		cbits[i] = cbits[i&(i-1)]+1;
	int numTests(rd());
	For(test, 1, numTests) {
		printf("Case #%d:", test);
		scanf("%d%d", &m, &n);
		Rep(i, m) {
			scanf("%s", a[i]);
			assert(strlen(a[i]) == n);
			row[i] = 0;
			Rep(j, n)
				row[i] = row[i]*2+int(a[i][j] == 'x');
		}
		vi v, v2;
		Rep(i, 1<<n) {
			bool good = true;
			Rep(j, n)
				if ((i&(1<<j)) && (i&(1<<(j+1))))
					good = false;
			if (good) {
				v.push_back(i);
				int mask = 0;
				Rep(k, n)
					if (k > 0 && (i&(1<<(k-1))) || (i&(1<<(k+1))))
						mask |= 1<<k;
				v2.push_back(mask);
			}
		}
		Fill(dp, 0);
		int res = 0;
		Rep(i, Size(v)) if ((v[i]&row[0]) == 0)
			checkMax(res, dp[0][v[i]] = cbits[v[i]]);
		For(i, 1, m-1) {
			Rep(j, Size(v)) if ((v[j]&row[i]) == 0) {
				int& r = dp[i][v[j]];
				Rep(k, 1<<n) {
					if ((v2[j]&k) == 0)
						checkMax(r, cbits[v[j]]+dp[i-1][k]);
				}
				checkMax(res, r);
			}
		}
		printf(" %d\n", res);
	}

	exit(0);
}
