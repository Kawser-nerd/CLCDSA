#include <stdio.h>

int main(void)
{
  
  int n,m;
  
  scanf("%d%d",&n,&m);
  
  for(int i=1;n>=i;i++){
    if(i!=m){
      printf("%d",i);
      break;
    }
  }
  
  return 0;
  
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^