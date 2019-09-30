#include<stdio.h>
int n, i, j, flag;
char S[201];
int main(){
  scanf("%s", S);
  while(S[n]){n++;}
  i=(n>>1)-1;
  while(1){
    flag=1;
    for(j=0; j<i; j++){
      if(S[j] != S[j+i]){flag=0; break;}
    }
    if(flag){break;}
    i--;
  }
  printf("%d\n", i*2);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^