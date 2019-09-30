#include <stdio.h>

int main(void){
	int n,a,b,w=0;
	scanf("%d%d%d",&n,&a,&b);

	while(1){
		n-=(a+b);
		if(n<=0){
			if(n+b>0) w=1;
			break;
		}
	}
	printf("%s\n",w==1?"Bug":"Ant");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^