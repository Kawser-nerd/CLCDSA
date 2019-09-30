#include <stdio.h>

int main(void)
{
	int x,a,b,sum,remaining,change;
	scanf("%d\n%d\n%d",&x,&a,&b);
	
	remaining=x-a;
	
	if(remaining%b==0){
		sum=remaining/b;
	}else{
		while(remaining%b!=0){
			remaining--;
		}
		sum=remaining/b;
	}
	
	change=x-a-(b*sum);
	
	printf("%d\n",change);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%d\n%d",&x,&a,&b);
  ^