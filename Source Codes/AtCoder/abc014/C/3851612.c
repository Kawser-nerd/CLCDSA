#include<stdio.h>
int N, a, b, num[1000002], now, max, i;
int main(){
  scanf("%d", &N);
  for(i=0; i<N; i++){
    scanf("%d%d", &a, &b);
    num[a]++;
    num[b+1]--;
  }
  for(i=0; i<1000002; i++){
    now+=num[i];
    if(now>max){max=now;}
  }
  printf("%d\n", max);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^