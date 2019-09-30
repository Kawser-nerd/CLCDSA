#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    fprintf(stderr, "tc%d\n", tc);
    long long C, D, V;
    scanf("%lld%lld%lld", &C, &D, &V);
    long long coins[111];
    for (int i = 0; i < D; i++) scanf("%lld", &coins[i]);

    int dn = 0;

    int added = 0;
    long long X = 0;
    while (X < V) {
      if (dn == D || coins[dn] > (X+1)) {
        fprintf(stderr, "adding %lld\n", X+1);
        added++;
        X += C * (X+1);
      } else {
        fprintf(stderr, "using  %lld\n", coins[dn]);
        X += C * coins[dn];
        dn++;
      }
    }

    printf("Case #%d: %d\n", tc, added);
  }
}
