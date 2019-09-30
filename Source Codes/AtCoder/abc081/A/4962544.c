#include <stdio.h>
 
int main(void){
  char S[3];
  int i, cnt = 0;
  scanf("%s", S);
  for(i=0;i<3;i++){
    if(S[i] == '1'){
      cnt++;
    }
  }
  printf("%d", cnt);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^