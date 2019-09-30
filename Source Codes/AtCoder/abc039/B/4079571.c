#include <stdio.h>
int main(){
      int x;
      scanf("%d",&x);
      for(int i=1;i<=300;i++){
      if(i*i*i*i==x){printf("%d",i);
      return 0;}
      }
} ./Main.c: In function ‘main’:
./Main.c:4:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&x);
       ^