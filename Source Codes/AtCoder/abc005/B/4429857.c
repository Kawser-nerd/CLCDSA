#include <stdio.h>
int main(void){
	int n,i=0,t,min=101;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		if(t<=min) min=t;
	}
	printf("%d\n",min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^