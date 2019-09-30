#include <stdio.h>
#include <string.h>
 
int main(){
  int n,a,b;
  scanf("%d %d %d",&n,&a,&b);
  if((b-a)%2==0){
    printf("Alice\n");
  }
  else{
    printf("Borys\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&a,&b);
   ^