#include <stdio.h>
int main(void){
  int i,s[3],e[3],tokuten=0;
  for(i=0;i<3;i++){
    scanf("%d%d",&s[i],&e[i]);
    tokuten+=s[i]*e[i]/10;
  }
  printf("%d\n",tokuten);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&s[i],&e[i]);
     ^