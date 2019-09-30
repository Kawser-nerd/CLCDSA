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
typedef long long ll;


void init() {
}


int split(int n, int N) {
  for (int x = N; x >= 1; --x)
    if (n % x == 0) return x;
  assert(0);
  return 0;
}


void solve(int P) {

  int N, M, A;
  scanf("%d%d%d", &N, &M, &A);
  
  int x1, y1, x2, y2;
  for (x1 = 1; x1 <= N; ++x1) {
    for (y2 = M; x1*y2 >= A; --y2) {
      if (x1*y2 < A) continue;
      int rem = x1*y2 - A;
      x2 = y1 = 0;
      if (!rem) goto found;
      x2 = split(rem, N);
      y1 = rem/x2;
      if (y1 <= M) {
	//	printf("x1 %d y2 %d, rem %d -> %d %d\n", x1, y2, rem, x2, y1);
	assert(x1*y2 - x2*y1 == A);
	goto found;
      }
    }
  }
  printf("Case #%d: IMPOSSIBLE\n", P);
  return;

 found:
  assert(x1 <= N && x2 <= N && y1 <= M && y2 <= M);
  printf("Case #%d: %d %d %d %d %d %d\n", P, 0, 0, x1, y1, x2, y2);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
