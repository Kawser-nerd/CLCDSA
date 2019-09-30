#include<stdio.h>

int main(void)
{
  int a[6]={1,2,3,4,5,6};
  int n;
  int i;
  int temp;

  scanf("%d",&n);

  n=n%30;
  if(n==0){
    n=30;
  }
  
  for(i=0;i<n;i++)
    {
      temp=a[i%5];
      a[i%5]=a[(i%5)+1];
      a[i%5+1]=temp;
    }

  for(i=0;i<6;i++)
    {
      printf("%d",a[i]);
    }
  printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^