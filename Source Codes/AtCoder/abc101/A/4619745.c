#include<stdio.h>
int main(void){
  int i,t=0;
  char S[4];
  scanf("%s",S);
  for(i=0;i<4;i++){
    if(S[i]=='+'){
      t++;
    }else{
      t--;
    }
  }
  printf("%d\n",t);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^