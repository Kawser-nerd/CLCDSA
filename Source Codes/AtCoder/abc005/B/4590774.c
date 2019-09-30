#include<stdio.h>

int main(void)
{
  int n;
  int t[100]={0};
  int i;
  int min;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&t[i]);
    }

  min=t[0];
  for(i=1;i<n;i++)
    {
      if(t[i]<min){
	min=t[i];
      }
    }
  printf("%d\n",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:13:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&t[i]);
       ^