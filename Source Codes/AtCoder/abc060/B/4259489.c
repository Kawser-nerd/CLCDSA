#include <stdio.h>
int main(void){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  for(int i=1;i<=b*a;i++){
    if(a*i%b==c) {printf("YES");return 0;}
  }
  printf("NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^