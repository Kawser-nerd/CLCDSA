#include <stdio.h>
int main(void){
	int a,b,i=0,honsuu=0;
	scanf("%d%d",&a,&b);
	while(honsuu<b){
		i++;
		honsuu+=a;
	}
	printf("%d\n",i);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^