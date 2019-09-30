#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define d(...) // fprintf(stderr, __VA_ARGS__)

void test(int casenum) {
  char buf[101];
  scanf(" ");
  int len;
  scanf("%s%n", buf, &len);
  char last = '+';
  int flips = 0;
  for (const char *p = buf + len - 1; p >= buf; --p) {
    if (*p != last) {
      last = *p;
      ++flips;
    }
  }
  printf("Case #%d: %d\n", casenum, flips);
}

int main() {
  int t;
  scanf("%d", &t);
  for  (int i = 1; i <= t; ++i) {
    test(i);
  }
  return 0;
}
