#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
typedef int64_t i64;

int main() {
  i64 T;
  scanf("%lld", &T);
  for (i64 zz = 1; zz <= T; zz++) {
    i64 D, N;
    scanf("%lld %lld", &D, &N);
    double last_time = 0;
    for (i64 i = 0; i < N; i++) {
      i64 K, S;
      scanf("%lld %lld", &K, &S);
      last_time = max(last_time, static_cast<double>(D - K)/ S);
    }
    printf("Case #%lld: %.09f\n", zz, D / last_time);
  }
}
