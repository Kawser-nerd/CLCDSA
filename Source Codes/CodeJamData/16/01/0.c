#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define d(...) // fprintf(stderr, __VA_ARGS__)

void test(int casenum) {
  int counts[26];
  memset(counts, 0, 26 * sizeof(int));
  char buf[100];
  long n;
  scanf(" %d ", &n);
  long cur = 0;
  d("Input: %d\n", n);
  if (!n) {
    printf("Case #%d: INSOMNIA\n", casenum);
    return;
  }
  int remaining = 10;
  while (remaining) {
    cur += n;
    sprintf(buf, "%d", cur);
    for (const char *p = buf; *p; ++p) {
      int offset = *p - '0';
      d("low: %d\n", offset);
      if (!counts[offset]) {
        counts[offset] = 1;
        --remaining;
      }
    }
  }
  printf("Case #%d: %d\n", casenum, cur);
}

int main() {
  int t;
  scanf("%d", &t);
  for  (int i = 1; i <= t; ++i) {
    test(i);
  }
  return 0;
}
