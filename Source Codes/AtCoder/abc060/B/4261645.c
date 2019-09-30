#include <stdio.h>

int main(void){
  int A,B,C;
  scanf("%d%d%d",&A,&B,&C);

  int flag[B];
  int ans = 0;
  for(int i = 0;i < B;i++) flag[i] = 0;

  for(int i = 1;;i++){
    if((A*i)%B == C){
      ans = 1;
      break;
    }
    if(flag[(A*i)%B]) break;
    flag[(A*i)%B] = 1;
  }

  if(ans) printf("YES\n");
  else printf("NO\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&C);
   ^