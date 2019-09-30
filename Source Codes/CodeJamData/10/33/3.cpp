#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

/* PREWRITTEN CODE */

#define ALL(x) x.begin(),x.end()
#define PB push_back


#define FOR(i,p,k) for (int i=p; i<k; i++)
#define REP(i,n) for (int i=0; i<n; i++)
#define SIZE(x) (int)x.size()
/* COMPETITION CODE */

int chti (char c) {
	if ('0' <= c && c <= '9') return (c - '0');
	return (c - 'A') + 10;
}

char bd[600][600];

int M, N;
char code[600][600];

void makebd() {
	REP (i, M) {
		REP (j, N) {
			int c = chti(code[i][j]);
			REP (z, 4) {
				bd[i][4 * j + 3 - z] = (c % 2);
				c /= 2;
			}
		}
	}
	REP (i, M) REP (j, N) if ((i + j) % 2) bd[i][j] = 1 - bd[i][j];
}

int dyn[600][600];

char get (int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return 2;
	return bd[y][x];
}

void makedyn() {
	for (int i = N; i >= 0; i--) for (int j = M; j >= 0; j--) {
		if (get(i, j) == 2) dyn[i][j] = 0;
		else {
			if (get(i+1,j) == get(i,j) && get(i,j+1) == get(i,j)) {
				dyn[i][j] = min(dyn[i][j+1], dyn[i+1][j]) + 1;
				if (get(i+dyn[i][j] - 1, j + dyn[i][j] - 1) != get(i,j)) dyn[i][j] -= 1;
			} else {dyn[i][j] = 1;}
		}
	}
}

int res[600];

void force(int x, int y, int s) {
	if (dyn[x][y] < s) return;
	res[s] += 1;
	for (int i = x; i < x+s; i++) for (int j = y; j < y+s; j++) dyn[i][j] = 0;
	for (int i = x-s+1; i < x+s; i++) for (int j = y-s+1; j < y+s; j++) if (get(i,j) != 2) {
		dyn[i][j] = min(dyn[i][j], max(max(x-i, y-j),0));
	}
}

int main () {
  int number_of_tests;
  scanf("%d", &number_of_tests);
  REP (test_number, number_of_tests) {
    printf("Case #%d: ", test_number+1);
  	scanf("%d %d", &M, &N);
		REP (i, M) scanf("%s", code[i]);
    makebd();
		makedyn();
		REP (i, 600) res[i] = 0;
		for (int s = 513; s > 0; s--) {
			for (int y = 0; y < M; y++) for (int x = 0; x < N; x++) {
				force(x,y,s);
			}
		}
		vector<pair<int,int> > r;
		for (int s = 513; s > 0; s--) if (res[s] > 0) r.PB(make_pair(s, res[s]));
		printf("%d\n", SIZE(r));
		REP (i, SIZE(r)) {
			printf("%d %d\n", r[i].first, r[i].second);
		}
  }
  return 0;
}

