# include <stdio.h>

int main(){
  char S[4][4];
  int i;
  for(i=0;i<3;i++){
    scanf("%s",S[i]);
  }
  printf("%c%c%c\n",S[0][0],S[1][1],S[2][2]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S[i]);
     ^