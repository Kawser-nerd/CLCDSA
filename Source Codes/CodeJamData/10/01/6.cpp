#include "climits"
#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "stack"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;

int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    int n; i64 k; scanf("%d %lld", &n, &k);
    k &= (1LL << n) - 1;
    if (k + 1 != (1LL << n)) printf("Case #%d: OFF\n", Ti);
    else printf("Case #%d: ON\n", Ti);
  }
  return 0;
}
