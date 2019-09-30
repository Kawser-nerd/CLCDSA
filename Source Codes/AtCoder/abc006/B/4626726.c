#include <stdio.h>
#define mod 10007   
  
int a[1000000];

int main(void){
  int N;
  scanf("%d",&N);

  a[0] = 0;
  a[1] = 0;
  a[2] = 1;

  for(int i = 3;i < N;i++){
    a[i] = a[i-1]+a[i-2]+a[i-3];
    a[i] %= mod;
  }

  printf("%d\n",a[N-1]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^