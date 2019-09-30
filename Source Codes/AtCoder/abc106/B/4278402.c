#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
  int n, ans = 0;

  if(scanf("%d", &n) == 1);

  for(int i = 1; i <= n; i += 2) {
    int count = 0;
    for(int j = i; j > 0; j--) {
      if(i % j == 0) {
        count++;
      }
    }
    if(count == 8) {
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;
}