#include <stdio.h>
int main(void){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	while(1){
		if(n%a==0 && n%b==0){
			printf("%d\n",n);
			break;
		}
		n++;
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&n);
  ^