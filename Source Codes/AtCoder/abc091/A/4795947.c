// https://atcoder.jp/contests/abc091/tasks/abc091_a
#include <stdio.h>

int main(int argc, char **argv) {
  int a, b, c;

  while (scanf("%d %d %d", &a, &b, &c) != EOF) {
    if (a + b >= c) {
      puts("Yes");
    } else {
      puts("No");
    }
  }

  return 0;
}