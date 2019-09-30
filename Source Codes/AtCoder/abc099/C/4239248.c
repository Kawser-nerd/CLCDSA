#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);
  int ans = N;
  
  for(int i = 0;i <= N;i++){
    int cc = 0;
    int t = i;
    while(t > 0) cc += t%6,t /= 6;
    t = N-i;
    while(t > 0) cc += t%9,t /= 9;
    if(ans > cc) ans = cc;
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^