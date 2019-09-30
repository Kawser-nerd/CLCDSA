#include <bits/stdc++.h>

using namespace std;

const int ANS = 210;
const int N = 1000010;

int f[ANS][N];
int a[N];
int last[13];
int pr[N][13];
char foo[N];

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
    scanf("%s", foo);
    int n = strlen(foo);
    for (int i = 0; i < n; i++) {
      a[i] = foo[i] - '0';
    }
    // input data ends
    if (qq < TEST_FROM || qq > TEST_TO) {
      continue;
    }
    printf("Case #%d: ", qq);
    fflush(stdout);
    // solution starts
    for (int c = 1; c <= 9; c++) {
      last[c] = -1;
    }
    for (int i = 0; i <= n; i++) {
      if (i < n) {
        last[a[i]] = i;
      }
      for (int c = 1; c <= 9; c++) {
        pr[i][c] = last[c];
      }
    }
    for (int i = 0; i <= n; i++) {
      f[0][i] = i;
    }
    int ans = 0;
    while (f[ans][0] < n) {
      ans++;
      for (int i = 0; i < n; i++) {
        f[ans][i] = i;
        for (int dig = 1; dig <= 9 && dig <= ans; dig++) {
          int pos = f[ans - dig][i];
          pos = pr[pos][dig];
          if (pos < i) {
            continue;
          }
          pos = f[ans - dig][pos + 1];
          f[ans][i] = max(f[ans][i], pos);
        }
      }
      f[ans][n] = n;
    }
    printf("%d\n", ans);
    // solution ends
    fflush(stdout);
    fprintf(stderr, "test %d solved, time = %d ms\n", qq, (int)clock());
  }
  return 0;
}
