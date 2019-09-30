#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
  int n;
  char s[102];
  long k;

  if(scanf("%s", s) == 1);
  if(scanf("%ld", &k) == 1);

  n = strlen(s);

  for(long i = 0; i < k && i < n; i++) {
    if(s[i] != '1') {
      printf("%c", s[i]);
      break;
    } else if(i == k - 1) {
      printf("1");
    }
  }

  return 0;
}