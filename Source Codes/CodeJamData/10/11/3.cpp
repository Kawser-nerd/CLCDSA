#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <numeric>
#include <cctype>
#include <climits>
using namespace std;

typedef long long int64; 
typedef unsigned long long uint64;

template<typename T> int size(const T& c) { return int(c.size()); }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> bool remin(T& x, T y) { if (x <= y) return false; x = y; return true; }
template<typename T> bool remax(T& x, T y) { if (x >= y) return false; x = y; return true; }

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n) - 1); i >= 0; --i)

vector<vector<char> > rotate(const vector<vector<char> >& board) {
	int n = size(board);
	vector<vector<char> > res(n, vector<char>(n));
	REP(i, n) REP(j, n)
		res[j][n-1-i] = board[i][j];
	return res;
}

bool check(const vector<vector<char> >& board, char ch, int k) {
	int n = size(board);
	const int di[] = {0, 1, 1, 1}, dj[] = {1, -1, 0, 1};
	REP(i, n) REP(j, n) REP(dir, 4) {
		int ci = i, cj = j, cnt = 0;
		while (0 <= ci && ci < n && 0 <= cj && cj < n && board[ci][cj] == ch) {
			++cnt;
			ci += di[dir]; cj += dj[dir];			
		}
		if (cnt >= k) return true;
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int ntests;
	scanf("%d", &ntests);
	FOR(test, 1, ntests) {
		printf("Case #%d: ", test);
		int n, k;
		scanf("%d%d", &n, &k);
		vector<vector<char> > board(n, vector<char>(n));
		REP(i, n) REP(j, n) scanf(" %c", &board[i][j]);
		board = rotate(board);
		REP(j, n) {
			int i1 = n-1;
			REPD(i, n) 
				if (board[i][j] != '.')
					board[i1--][j] = board[i][j];
			while (i1 >= 0) 
				board[i1--][j] = '.';
		}
		bool R = check(board, 'R', k), B = check(board, 'B', k);
		if (R && B) printf("Both\n");
		else if (R) printf("Red\n");
		else if (B) printf("Blue\n");
		else printf("Neither\n");
	}
}
