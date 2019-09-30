#include <stdio.h>

int main(void){
  char S[11];
  int i=0,res=0;
  scanf("%s",S);
  for(int i=0;S[i]!='\0';i++){
    int sum=0;
    for(int j=i;S[j]!='\0';j++){
      if(S[j]=='A' || S[j]=='C' || S[j]=='G' || S[j]=='T') sum++;
      else break;
    }
    if(sum>res) res=sum;
  }
  printf("%d\n",res);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^