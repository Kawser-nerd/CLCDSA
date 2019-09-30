#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
  int i, N;
  double x, T=0;
  char s[10];
  scanf("%d", &N);
  for (i=0;i<N;i++){
    scanf("%lf %s", &x, s);
    if (strcmp(s, "BTC") == 0){
      T += 380000 * x;
    } else {
      T += x;
    }
  }
  printf("%lf\n", T);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf %s", &x, s);
     ^