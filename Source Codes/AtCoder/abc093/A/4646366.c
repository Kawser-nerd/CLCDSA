#include<stdio.h>
int main()
{
  char x,y,z;
  scanf("%1s %1s %1s",&x,&y,&z);
  if(x!=y&&y!=z&&z!=x){
    printf("Yes");
  }else{
    printf("No");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%1s %1s %1s",&x,&y,&z);
   ^