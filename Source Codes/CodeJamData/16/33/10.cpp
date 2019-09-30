#include <cstdio>

void disp(int x, int y, int z) {
  printf("%d %d %d\n", x + 1, y + 1, z + 1);
}

void solve(int a, int b, int c, int K) {
  if (a == 1 && b == 1 && c == 1) {
    printf("1\n");
    printf("1 1 1\n");
    return;
  }

  int lim = K;
  if (c < lim) lim = c;
  printf("%d\n", lim * a * b);
  for(int k = 0; k < lim; ++k) {
    for(int x = 0; x < a; ++x) {
      for(int y = 0; y < b; ++y) {
        disp(x, y, ((x + y) % b + k) % c);
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; ++t) {
    int a, b, c, K;
    scanf("%d %d %d %d", &a, &b, &c, &K);
    printf("Case #%d: ", t);
    solve(a, b, c, K);
  }
}
