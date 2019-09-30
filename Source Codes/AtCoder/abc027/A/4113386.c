#include <stdio.h>

int main(void){
	int a[3];
	for(int i = 0; i < 3; i++)
		scanf("%d", a + i);
	if(a[0] == a[1])
		printf("%d\n", a[2]);
	else if(a[0] == a[2])
		printf("%d\n", a[1]);
	else
		printf("%d\n", a[0]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", a + i);
   ^