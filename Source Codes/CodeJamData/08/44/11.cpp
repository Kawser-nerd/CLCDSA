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

int n;
int a[16][16], b[16][16];
int memo[1<<16][16][16];

int solve(int mask, int first, int last, int cnt) {
	if (cnt == n)
		return b[first][last];
	int& res = memo[mask][first][last];
	if (res == -1) {
		res = INT_MAX;
		Rep(i, n) {
			if (!(mask&(1<<i))) 
				checkMin(res, solve(mask|(1<<i), first, i, cnt+1)+a[last][i]);			
		}
	} 
	assert(res < INT_MAX);
	return res;
}

int solve() {
	Rep(i, 1<<n) Rep(j, n) Rep(k, n)
		memo[i][j][k] = -1;
	int res = INT_MAX;
	Rep(i, n) 
		checkMin(res, solve(1<<i, i, i, 1));
	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int numTests(rd());
	For(test, 1, numTests) {
		n = rd();
		string s(rs());
		Fill(a, 0);
		Fill(b, 0);
		for (int i = 0; i < Size(s); i += n) {
			Rep(p, n) Rep(q, n) {
				if (s[i+p] != s[i+q])
					++a[p][q];
				if (i+n < Size(s) && s[i+n+q] != s[i+p])
					++b[p][q];
			}
		}
		printf("Case #%d: %d\n", test, solve()+1);
	}

	exit(0);
}
