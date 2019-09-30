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

const int inf = 123456789;
int n, n1, n2, need;
int g[20000], c[20000], bit[20000], dp[20000];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int numTests(rd());
	For(test, 1, numTests) {
		n = rd();
		need = rd();
		n1 = (n-1)/2;
		n2 = (n+1)/2;
		Rep(i, n1) {
			g[i] = rd();
			c[i] = rd();
		}
		Rep(i, n2) {
			bit[n1+i] = rd();
			dp[n1+i] = inf;
		}
		Repd(i, n1) {
			int i1 = i*2+1, i2 = i*2+2;
			if (g[i])
				bit[i] = bit[i1]&bit[i2];
			else
				bit[i] = bit[i1]|bit[i2];
			dp[i] = inf;
			Rep(x, c[i]+1) {
				Rep(x1, 2) Rep(x2, 2) {
					int cost = x+(x1 ? dp[i1] : 0)+(x2 ? dp[i2] : 0);
					int b1 = bit[i1]^x1, b2 = bit[i2]^x2, b;
					if (g[i]^x) 
						b = b1&b2;
					else
						b = b1|b2;
					if (b != bit[i])
						checkMin(dp[i], cost);
				}
			}
		}
		printf("Case #%d:", test);
		if (bit[0] == need)
			printf(" 0\n");
		else if (dp[0] < inf)
			printf(" %d\n", dp[0]);
		else
			printf(" IMPOSSIBLE\n");
	}

	exit(0);
}
