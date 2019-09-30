#include <stdio.h>

int main(void){
  int N,cnt,cnt8 = 0;
  scanf("%d",&N);
  
  int i,j;
  for(i = 1;i <= N; i += 2){
    cnt = 0;
    for(j = 1;j <= i; j += 2){
      if(!(i % j))	cnt++;
    }
    if(cnt == 8) ++cnt8;
  }
  printf("%d\n",cnt8);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^