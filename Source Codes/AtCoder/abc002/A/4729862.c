# include <stdio.h>

int main (void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	if (x > y){
	printf("%d\n",x);
	}
	else
	{
	printf("%d\n",y);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&x,&y);
  ^