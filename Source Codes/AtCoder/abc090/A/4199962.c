#include<stdio.h>

int main(void){
  char s[3][3];
  int i,j;
  for(i=0;i<3;i++){
    scanf("%s",s[i]);
    printf("%c",s[i][i]);
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^