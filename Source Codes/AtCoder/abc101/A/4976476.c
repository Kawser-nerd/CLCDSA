#include<stdio.h>
int main(void){
  char s[4];
  int i;
  int sum=0;
  
  for(i=0;i<4;i++){
    scanf("%c",&s[i]);
    if(s[i]=='+')
      sum++;
    else
      sum--;
  }
  printf("%d",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&s[i]);
     ^