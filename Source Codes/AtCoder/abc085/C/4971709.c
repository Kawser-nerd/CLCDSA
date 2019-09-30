#include <stdio.h>
int main(){
  int N,Y,a,b,c;
  scanf("%d %d",&N,&Y);
  for(a=0;(10000*a<=Y) && (a<=N);a++){
    for(b=0;(10000*a+5000*b<=Y) && (a+b<=N);b++){
      c=Y/1000-10*a-5*b;
      if(a+b+c==N){
        printf("%d %d %d\n",a,b,c);
        return 0;
      }
    }
  }
  printf("-1 -1 -1\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&Y);
   ^