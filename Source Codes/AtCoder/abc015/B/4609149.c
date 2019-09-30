#include<stdio.h>

int main(void)
{
  int n;
  int a[100];
  int i;
  int number=0;
  int sum;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
  for(i=0;i<n;i++)
    {
      if(a[i]!=0){
	number++;
	sum+=a[i];
      }
    }

  if(sum%number==0) {
      printf("%d\n",sum/number);
  }else {
    printf("%d\n",sum/number+1);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:14:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a[i]);
       ^