/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
//#include <string>
//#include <map>
//#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;

void init() {
}

int S, k;
int best[16][1<<16];
char text[60000];
int gain[100][100];
int first;


int Gain(int x, int y) {
  int &g = gain[x][y];
  if (g == -1) {
    g = 0;
    for (int i = 0; i+y < S; i += k) 
      g += (text[i+x] == text[i+y]);
  }
  return g;
}

int Best(int x, int L) {
  if (!L) return Gain(x, k+first);
  int &res = best[x][L];
  if (res == -1) {
    res = 0;
    for (int y = 0; y < k; ++y)
      if (L & (1<<y))
	res >?= Best(y, L & ~(1<<y)) + Gain(x, y);
  }
  return res;
}

void solve(int P) {

  scanf("%d%s", &k, text);
  S = strlen(text);
  memset(gain, -1, sizeof(gain));

  int res = 0;
  for (first = 0; first < k; ++first) {
    memset(best, -1, sizeof(best));
    res >?= Best(first, (1<<k)-1-(1<<first));
  }
  
  printf("Case #%d: %d\n", P, S - res);
  fprintf(stderr, "Case #%d: %d\n", P, S - res);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
