#include <stdio.h>
int main(){
  int n,y,a,b,c;
  scanf("%d%d",&n,&y);
  for(a=0;a<=n;a++){
    for(b=0;b<=n-a;b++){
      for(c=0;c<=n-a-b;c++){
        //printf("%d %d %d\n",a,b,c);
        if(((10*a+5*b+c)==(y/1000))&&(a+b+c==n)){
          printf("%d %d %d",a,b,c);
          return 0;
        }
      }
    }
  }
  printf("-1 -1 -1");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&y);
   ^