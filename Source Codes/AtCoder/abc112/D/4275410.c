#include <stdio.h>

int main(){
  int N,M;
  scanf("%d%d",&N,&M);

  int gcd=1;
  int p;//????
  p=M/N;
  int a=1;

  while(p>=2){
    a=1;
    for(int i=p;i>=2;i--){
      if(M%i==0){
        M=M/i;
        gcd=gcd*i;
        p=M/N;
        a=0;
        break;
      }
    }
    if(a==1) break;
  }

  printf("%d\n",gcd);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^