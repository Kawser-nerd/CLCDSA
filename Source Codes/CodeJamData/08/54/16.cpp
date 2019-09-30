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

const int mod = 10007;

int dp[100][100];

void fillDP() {
	Fill(dp, 0);
	dp[0][0] = 1;
	Rep(i, 100) Rep(j, 100) {
		if (i-1 >= 0 && j-2 >= 0)
			dp[i][j] += dp[i-1][j-2];
		if (i-2 >= 0 && j-1 >= 0)
			dp[i][j] += dp[i-2][j-1];
	}
}

int64 countWays(int r, int c) {
	if (r < 0 || c < 0)
		return 0;
	assert(r < 100 && c < 100);
	return dp[r][c];
}

int h, w;
int64 res;
vpii v;

void solve(int cnt, int pos, int lastR, int lastC, int64 cur) {
	while (pos < Size(v)) {
		int64 t = countWays(v[pos].first-lastR, v[pos].second-lastC);
		if (t > 0) 
			solve(cnt+1, pos+1, v[pos].first, v[pos].second, cur*t%mod);
		++pos;
	}
	cur *= countWays(h-lastR, w-lastC);
	if (cnt%2 == 0)
		res += cur;
	else
		res -= cur;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	fillDP();
	int numTests(rd());
	For(test, 1, numTests) {
		printf("Case #%d:", test);
		int r;
		scanf("%d%d%d", &h, &w, &r);
		v.resize(r);
		Rep(i, r)
			scanf("%d%d", &v[i].first, &v[i].second);
		sort(All(v));
		/*assert(Size(v) == 0 || v[0] != MP(1, 1));
		assert(Size(v) == 0 || v.back() != MP(h, w));
		res = 0;
		solve(0, 0, 1, 1, 1);*/
		Fill(dp, 0);
		Rep(i, Size(v)) {
			dp[v[i].first-1][v[i].second-1] = -1;
		}
		if (dp[0][0] != -1)
			dp[0][0] = 1;
		Rep(i, h) Rep(j, w) {
			if (dp[i][j] != -1) {
				if (i-2 >= 0 && j-1 >= 0 && dp[i-2][j-1] > 0)
					dp[i][j] += dp[i-2][j-1];
				if (i-1 >= 0 && j-2 >= 0 && dp[i-1][j-2] > 0)
					dp[i][j] += dp[i-1][j-2];
				dp[i][j] %= mod;
			}
		}
		res = dp[h-1][w-1];
		printf(" %I64d\n", (res%mod+mod)%mod);
	}

	exit(0);
}
