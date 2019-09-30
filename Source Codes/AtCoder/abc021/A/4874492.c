#include <stdio.h>

int main(){
	int a,i;
	scanf("%d",&a);
	printf("%d\n",a);
	for(i=0;i<a;i++){
		
		printf("1\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^