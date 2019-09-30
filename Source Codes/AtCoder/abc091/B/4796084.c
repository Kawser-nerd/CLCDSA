// https://atcoder.jp/contests/abc091/tasks/abc091_b
#include <stdio.h>
#include <string.h>

int n, m;
char s[101][11], t[101][11];

int point(char *str) {
  int i, p = 0;
  for (i = 0; i < n; i++) {
    if (strcmp(str, s[i]) == 0) {
      p++;
    }
  }
  for (i = 0; i < m; i++) {
    if (strcmp(str, t[i]) == 0) {
      p--;
    }
  }
  return p;
}

int solv() {
  int i, max = 0, p;

  for (i = 0; i < n; i++) {
    p = point(s[i]);
    if (p > max) {
      max = p;
    }
  }
  for (i = 0; i < m; i++) {
    p = point(t[i]);
    if (p > max) {
      max = p;
    }
  }

  return max;
}

int main(int argc, char **argv) {
  int i;

  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
      scanf("%s", t[i]);
    }

    printf("%d\n", solv());
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%s", s[i]);
       ^
./Main.c:49:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &m);
     ^
./Main.c:51:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%s", t[i]);
       ^