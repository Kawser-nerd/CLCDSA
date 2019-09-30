#include <stdio.h>
int main(){
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  if(a==c||a==d||b==c||b==d){
    puts("YES");
  }
  else {
    puts("NO");
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^