#include <stdio.h>
int main(void){
int n;
  int a,b;
  int count;
  int total=0;
  scanf("%d",&n);
  for(count=0;count!=n;count++){
  scanf("%d %d",&a,&b);
  total=total+(b-a+1);
  }
  printf("%d",total);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^