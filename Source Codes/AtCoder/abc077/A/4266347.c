#include<stdio.h>

int main(void){
  char s[2][3];
  int i,j;
  for(i=0;i<3;i++){
    scanf("%c",&s[0][i]);
  }
  getchar();
  for(i=0;i<3;i++){
    scanf("%c",&s[1][i]);
  }
  int flag=1;
  for(j=0;j<3;j++){
    //printf("%c %c\n",s[0][j],s[1][2-j]);
    if(s[0][j]!=s[1][2-j]) flag=0;
  }
  if(flag) printf("YES\n");
  else printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&s[0][i]);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&s[1][i]);
     ^