/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;

typedef pair<int, int> pii;

void init() {
}

int offs;
int best[350];
pii ivals[350];


int go() {
  int cnt = 0;
  int at = 1;
  for (int i = 0; i < offs; ) {
    if (ivals[i].first > at) return 1<<28;
    int best = i;
    int j;
    for (j = i+1; j < offs && ivals[j].first <= at; ++j) {
      if (ivals[j].second > ivals[best].second) best = j;
    }
    ++cnt;
    at = ivals[best].second + 1;
    i = j;
    if (at > 10000) return cnt;
  }
  if (at <= 10000) return 1<<28;
  return cnt;
}

struct offer {
  int x, y, col;
  bool operator<(const offer &o)const {
    return x < o.x;
  }
};

void solve(int P) {
  map<string, int> COL;
  int N;
  scanf("%d", &N);
  offer O[1000];
  for (int i = 0; i < N; ++i) {
    char str[1000];
    scanf("%s%d%d", str, &O[i].x, &O[i].y);
    int &c = COL[str];
    if (c == 0) c = COL.size();
    O[i].col = c;
    //    printf("%d %d col %d\n", O[i].x, O[i].y, c);
  }
  sort(O, O+N);
  int cols = COL.size(), res = 1<<28;
  if (cols < 3) cols = 3;
  for (int a = 1; a <= cols; ++a)
    for (int b = 1; b < a; ++b)
      for (int c = 1; c < b; ++c) {
	offs = 0;
	for (int i = 0; i < N; ++i)
	  if (O[i].col == a ||
	      O[i].col == b ||
	      O[i].col == c)  {
	    ivals[offs].first = O[i].x;
	    ivals[offs].second = O[i].y;
	    ++offs;
	  }
	//	printf("try a %d b %d c %d -> %d offs\n",	       a, b, c, offs);
	res = min(res, go());
      }
  
  if (res >= 1<<28)
    printf("Case #%d: IMPOSSIBLE\n", P);
  else
    printf("Case #%d: %d\n", P, res);
  fprintf(stderr, "%d -> %d\n", P, res);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
