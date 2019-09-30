# include <stdio.h>

int main(){
  char S[3];
  int i,sum=700;
  scanf("%s",S);
  for(i=0;i<3;i++){
    if(S[i]==111) sum+=100;
  }
  printf("%d\n",sum);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^