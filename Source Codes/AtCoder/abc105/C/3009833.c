#include<stdio.h>
int main(void)
{
  int x,i,j,answer[35];
  scanf("%d",&x);
  answer[0]=0;
  for(i=1;i<35;i++)
  {
    answer[i]=0;
  }
  
  if(x==0) printf("0");
  else
  {
  
  for(i=0;i<35;i++)
  {
    if(x%2!=0)
    {
      answer[i]=1;
      if(i%2==0) x=x-1;
      else x=x+1;
    }
    x=x/2;
  }
  
  for(j=34;j>=0;j--)
  {
    if(answer[j]==1) break;
  }
  while(j>=0)
  {
    printf("%d",answer[j]);
    j--;
  }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^