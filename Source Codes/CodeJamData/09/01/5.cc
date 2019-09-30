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

using namespace std;

typedef long long ll;

int L, D, cases;
char dict[10000][20];

void init() {
  scanf("%d%d%d", &L, &D, &cases);
  for (int i = 0; i < D; ++i) scanf("%s", dict[i]);
  fprintf(stderr, "read %d words\n", D);
}


void solve(int P) {
  char query[10000];
  scanf("%s", query);

  int mask[100];
  for (int i = 0, j = 0; query[j]; ++j, ++i) {
    if (query[j] == '(') {
      mask[i] = 0;
      for (++j; query[j] != ')'; ++j)
	mask[i] |= 1<<(query[j]-'a');
    } else
      mask[i] = 1<<(query[j]-'a');
  }

  int ans = 0;
  for (int j = 0; j < D; ++j) {
    bool bad = false;
    for (int k = 0; !bad && k < L; ++k)
      if (!(mask[k] & (1<<(dict[j][k]-'a'))))
	bad = true;
    if (!bad) ++ans;
  }
  
  printf("Case #%d: %d\n", P, ans);
}

int main(void) {
  init();
  for (int i = 1; i <= cases; ++i) solve(i);
  return 0;
}
