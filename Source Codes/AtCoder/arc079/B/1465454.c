#include<stdio.h>

int main() {
  long long k;
  int i;
  scanf("%lld", &k);
  long long ans[55];
  long long sho = k/50;
  long long amari = k%50;
  for (i = 0; i < 50; i++) {
    ans[i] = 49+sho;
  }
  for (i = 0; i < amari; i++) {
    ans[i] = ans[i]+51-amari;
  }
  for (i = amari; i < 50; i++) {
    ans[i] = ans[i]-amari;
  }
  printf("50\n");
  for (i = 0; i < 50; i++) {
    printf("%lld ", ans[i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &k);
   ^