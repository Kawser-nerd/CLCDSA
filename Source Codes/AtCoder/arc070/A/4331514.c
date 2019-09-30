#include<stdio.h>
#define N 50000
int main()
{
	int m;
	int i;
	int n = 0;
	scanf("%d",&m);
    for(i = 1;i<=m;i++)
    {
    	n += i;
    	if(n >= m)
    	{
    		printf("%d",i);
    		break;
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^