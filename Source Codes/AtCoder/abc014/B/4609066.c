#include<stdio.h>

int main(void)
{
  int n;
  int x;
  int b[20]={0};
  int a[20]={0};
  int i,k=1;
  int sum=0;

  scanf("%d%d",&n,&x);
  for(i=0;i<n;i++)
    {
      b[i]=(x/k)%2;
      k=2*k;
     }
  
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
  for(i=0;i<n;i++)
    {
      if(b[i]==1)
	{
	  sum+=a[i];
	}
    }
  
  printf("%d\n",sum);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:21:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a[i]);
       ^