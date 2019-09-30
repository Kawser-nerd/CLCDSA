#include <stdio.h>

int main(void) {
	int n, x, i;
	
	scanf("%d %d", &n, &x);
	
	if(1<x&&x<2*n-1){
		printf("Yes\n");
		
		for(i=0;i<2*n-1;i++)
		printf("%d\n", (i+x+n-1)%(2*n-1)+1);
	}
	else
	printf("No\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &x);
  ^