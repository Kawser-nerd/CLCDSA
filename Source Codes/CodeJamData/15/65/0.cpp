#include <bits/stdc++.h>

using namespace std;

const int N = 777;

int a[N][N];

int main(int argc, char* argv[]) {
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  if (argc == 3) {
    sscanf(argv[1], "%d", &TEST_FROM);
    sscanf(argv[2], "%d", &TEST_TO);
  }
  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    // input data starts
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", a[i] + j);
      }
    }
    // input data ends
    if (qq < TEST_FROM || qq > TEST_TO) {
      continue;
    }
    printf("Case #%d: ", qq);
    fflush(stdout);
    // solution starts
    int total = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        total += a[i][j];
      }
    }
    vector <int> order(m);
    for (int i = 0; i < m; i++) {
      order[i] = i;
    }
    int ans = 0;
    do {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        int best = 0, now = 0;
        for (int j = 0; j < m; j++) {
          now += a[i][order[j]];
          best = min(best, now);
        }
        cur -= best;
      }
      ans = max(ans, cur);
    } while (next_permutation(order.begin(), order.end()));
    printf("%d\n", ans + total);
    // solution ends
    fflush(stdout);
    fprintf(stderr, "test %d solved, time = %d ms\n", qq, (int)clock());
  }
  return 0;
}
