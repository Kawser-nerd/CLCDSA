#include <stdio.h>

int main(void)
{
	int a,b,k;
	
	scanf("%d%d%d",&a,&b,&k);
	
	int x=0;
	int	y=k;
	int i=0;
	while(x<k&&a+x<b-k+1){
		printf("%d\n",a+x);
		x++;
	}
	
	while(y!=0){
		if(b-y+1>=a){
		printf("%d\n",b-y+1);
		}
		y--;
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&k);
  ^