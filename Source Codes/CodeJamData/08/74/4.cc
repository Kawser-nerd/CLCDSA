#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long ii;

int R, C;
string foo[15];

//2^16 * 16  burned * king pos
char val[1<<20];

int go(int state) {
  if (val[state]) {
    return val[state];
  }

  // unpack
  int kp = state & 15; state >>= 4;
  int bs = state;

  int ret = -1; // lose by default

  int kr = kp / 4, kc = kp % 4;
  for (int i = -1; i <= 1; i++)
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0) {
	int tr = kr + i;
	int tc = kc + j;
	if (tr == -1 || tr == 4 || tc == -1 || tc == 4) continue;
	int tp = 4*tr+tc;
	if (bs & (1 << tp)) continue;

	int ns = ((bs | (1 << kp)) << 4) + tp;
	if (go(ns) == -1) { // they lose, yay
	  ret = 1;
	  break;
	}
      }
    }

  return val[state] = ret;
}

int main() {
  int N; cin >> N;
  for (int it = 1; it <= N; it++) {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
      cin >> foo[i];
    }

    while (R < 4) {foo[R++] = "####";}
    for (int i = 0; i < R; i++) {
      while (foo[i].size() < 4)
	foo[i] += "#";
    }
    
    // turn it into a state
    memset(val, 0, sizeof(val));

    int start = 0;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) {
	if (foo[i][j] == '#')
	  start |= (1 << (4*i + j));
      }
    start *= 16;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
	if (foo[i][j] == 'K')
	  start += (4*i+j);

    int winner = go(start);

    printf("Case #%d: %c\n", it, (winner == 1) ? 'A' : 'B');
  }
}
