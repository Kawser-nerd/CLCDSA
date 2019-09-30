#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
  int n, h[102], ans = 0, kugiri = 0;

  if(scanf("%d", &n) == 1);

  for(int i = 0; i < n; i++) {
    if(scanf("%d", &h[i]) == 1);
  }

  while(kugiri != -1) {
    for(int i = 0; i < n; i++) {
      if(h[i] > 0) {
        kugiri = i;
        break;
      } else if(i == n - 1) {
        printf("%d", ans);
        kugiri = -1;
        break;
      }
    }
    for(int i = kugiri; i < n && kugiri != -1; i++) {
      if(i == n - 1) {
        ans++;
        for(int j = kugiri; j < n; j++) {
          h[j]--;
        }
        break;
      } else if(h[i] == 0) {
        ans++;
        for(int j = kugiri; j < i; j++) {
          h[j]--;
        }
        break;
      }
    }
  }

  return 0;
}