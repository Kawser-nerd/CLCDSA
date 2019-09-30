#include<stdio.h>

int main(void)
{
  int s1,s2,s3,e1,e2,e3;
  scanf("%d%d",&s1,&e1);
  scanf("%d%d",&s2,&e2);
  scanf("%d%d",&s3,&e3);

  printf("%d\n",s1*e1/10+s2*e2/10+s3*e3/10);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&s1,&e1);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&s2,&e2);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&s3,&e3);
   ^