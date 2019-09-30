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

#define right RIGHT
#define left LEFT

const int k = 3000+3000+10;
short up[k][k], right[k][k], left[k][k], down[k][k];
char s[1024*1024];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int numTests(rd());
	For(test, 1, numTests) {
		printf("Case #%d:", test);
		Fill(up, 0);
		Fill(right, 0);
		Fill(down, 0);
		Fill(left, 0);
		int n(rd());
		int x = k/2, y = k/2, d = 0;
		while (n --> 0) {
			int t;
			scanf("%s%d", s, &t);
			while (t --> 0) {
				for (int i = 0; s[i]; ++i) {
					if (s[i] == 'F') {
						int nx = x+dx[d], ny = y+dy[d];
						if (d == 0) 
							up[x][y-1] = down[x][y] = 1;
						else if (d == 1)
							right[x-1][y] = left[x][y] = 1;
						else if (d == 2)
							up[x-1][y-1] = down[x-1][y] = 1;
						else if (d == 3)
							right[x-1][y-1] = left[x][y-1] = 1;
						else
							assert(false);
						x = nx;
						y = ny;
					} else if (s[i] == 'L') {
						d = (d+1)&3;
					} else if (s[i] == 'R') {
						d = (d+3)&3;
					} else {
						assert(false);
					}
				}
			}
		}
		int res = 0;
		Rep(x, k) Rep(y, k) {
			if (x > 0)
				left[x][y] += left[x-1][y];
			if (y > 0)
				down[x][y] += down[x][y-1];
		}
		Repd(x, k) Repd(y, k) {
			if (x+1 < k)
				right[x][y] += right[x+1][y];
			if (y+1 < k)
				up[x][y] += up[x][y+1];
		}
		Rep(i, k) Rep(j, k) {
			if (left[i][j] > 0 && left[i][j]%2 == 0 && right[i][j] > 0 && right[i][j]%2 == 0)
				++res;
			else if (up[i][j] > 0 && up[i][j]%2 == 0 && down[i][j] > 0 && down[i][j]%2 == 0)
				++res;
		}
		printf(" %d\n", res);
	}

	exit(0);
}
