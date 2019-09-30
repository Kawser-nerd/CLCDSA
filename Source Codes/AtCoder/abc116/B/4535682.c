#include <stdio.h>

int func(int x) {
  int num;
  if(x % 2 == 0) {
    num = x / 2;
  } else {
    num = 3 * x + 1;
  }
  return num;
}

int main() {
  int s, i, j;
  int a[1000000];
  scanf("%d", &s);
  a[0] = s;
  for(i = 1; ; i++) {
    a[i] = func(a[i-1]);
    for(j = 0; j < i; j++) {
      if(a[i] == a[j]) {
        printf("%d\n", i + 1);
        return 0;
      }
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &s);
   ^