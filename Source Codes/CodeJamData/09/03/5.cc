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
#include <cstring>

using namespace std;

typedef long long ll;

void init(int N) {
}

const char *pattern = "welcome to code jam";

char line[10000];
int ways[10000][20];

int Ways(int pos, int pat) {
  if (pat == 19) return 1;
  if (!line[pos]) return 0;
  int &r = ways[pos][pat];
  if (r == -1) {
    r = Ways(pos+1, pat);
    if (pattern[pat] == line[pos])
      (r += Ways(pos+1, pat+1)) %= 10000;
  }
  return r;
}

void solve(int P) {
  fgets(line, 9000, stdin);
  memset(ways, -1, sizeof(ways));
  printf("Case #%d: %04d\n", P, Ways(0, 0));
}

int main(void) {
  int N;
  scanf("%d", &N);
  while (getchar() != '\n');
  init(N);
  for (int i = 1; i <= N; ++i) solve(i);
  return 0;
}
