#include<stdio.h>
#include<string.h>

#define max 51

int main(void)
{
  int n;
  int i,j;
  char name[max][max];
  int vote[max]={0};
  int tosen=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%s",name[i]);
    }
  for(i=0;i<n;i++)
    {
      for(j=i;j<max;j++)
	{
	  if(strcmp(name[i],name[j])==0)
	    {
	      vote[i]++;
	    }
	}
    }

  for(i=0;i<n;i++)
    {
      if(vote[i]>vote[tosen])
	{
	  tosen=i;
	}
    }

  printf("%s\n",name[tosen]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%s",name[i]);
       ^