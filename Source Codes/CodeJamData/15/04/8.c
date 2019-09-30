#include <stdio.h>
#include <string.h>

void solve(char *ans) {
  int X;
  int R;
  int C;
  scanf("%d %d %d", &X, &R, &C);
  if (R > C) {
    int tmp = R;
    R = C;
    C = tmp;
  }
  if (X > 6) {
    strcpy(ans, "RICHARD");
    return;
  }
  if (R >= X - 1 && C >= X && (R * C) % X == 0) {
    strcpy(ans, "GABRIEL");
  } else {
    strcpy(ans, "RICHARD");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  int i;
  for (i = 0; i < T; i++) {
    char ans[8];
    solve(ans);
    printf("Case #%d: %s\n", i + 1, ans);
  }
  return 0;
}
