#include <stdio.h>
int main(){
  int n, a, b;
  scanf("%d%d%d",&n,&a,&b);
  if((b-a)%2 == 1){
    puts("Borys");
  }else{
    puts("Alice");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^