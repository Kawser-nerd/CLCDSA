#include <stdio.h>

int main(void){
  int ans = 0;
  int s,e;
  for(int i = 0;i < 3;i++){
    scanf("%d%d",&s,&e);
    ans += s*e/10;
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&s,&e);
     ^