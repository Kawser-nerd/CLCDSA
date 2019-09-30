#include<stdio.h>

int main(void)
{
  int n,ng1,ng2,ng3,i;
  scanf("%d%d%d%d",&n,&ng1,&ng2,&ng3);

  if(n==ng1||n==ng2||n==ng3)
    {
      printf("NO\n");
      return 0;
    }
      
  for(i=0;i<100;i++)
    {
      if(n-3!=ng3&&n-3!=ng2&&n-3!=ng1){
	  n=n-3;
      } else if(n-2!=ng3&&n-2!=ng2&&n-2!=ng1){
	n=n-2;
      } else if(n-1!=ng3&&n-1!=ng2&&n-1!=ng1){
	n=n-1;
      }
    }

      if(n<=0){
	printf("YES\n");
      	return 0;
      }
    
  printf("NO\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&n,&ng1,&ng2,&ng3);
   ^