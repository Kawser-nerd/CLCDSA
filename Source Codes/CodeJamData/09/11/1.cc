/* GCJ'09 Template v.1e-9
 * Per Austrin
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int LIM = 12000000;

int cases;

bool happy[11][LIM];
int seen[LIM];
int ans[4000];

void genhappy(int b) {
  int cnt = 0;
  memset(seen, 0, sizeof(seen));
  for (int x = 2; x < LIM; ++x) {
    int y = x;
    do { 
      int z = 0;
      seen[y] = x;
      while (y) { int dig = y % b; z += dig*dig; y /= b; }
      y = z;
    } while (y >= x && seen[y] < x);
    happy[b][x] = (y == 1) || happy[b][y];
    cnt += happy[b][x];
  }
  fprintf(stderr, "b = %d: %d happies\n", b, cnt);
}

void init() {
  memset(happy, 0, sizeof(happy));
  memset(ans, -1, sizeof(ans));
  for (int b = 2; b <= 10; ++b) {
    genhappy(b);
  }
  scanf("%d", &cases);
}


void solve(int P) {
  char line[100000];
  fgets(line, 90000, stdin);
  istringstream in(line);
  bool use[20];
  int b, query = 0;
  for (int i = 0; i < 20; ++i) use[i] = false;
  while (in >> b) use[b] = true, query |= (1<<b);
  if (ans[query] != -1) {
    printf("Case #%d: %d\n", P, ans[query]);
    return;
  }
  for (int x = 2; x < LIM; ++x) {
    bool ok = true;
    for (int b = 2; b <= 10; ++b)
      if (use[b] && !happy[b][x]) ok = false;
    if (ok) {
      ans[query] = x;
      printf("Case #%d: %d\n", P, x);
      return;
    }
  }
  assert(0);
}

int main(void) {
  init();
  while (getchar() != '\n');
  for (int i = 1; i <= cases; ++i) solve(i);
  return 0;
}
