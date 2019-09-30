#include <stdio.h>

int main(void) {
	char a[4][4];
	for(int i=0; i<16; i++){
		scanf("%c%*c",&a[i/4][i%4]);
	}
	for(int i=0; i<16; i++){
		printf("%c ",a[3-(i/4)][3-(i%4)]);
		if (i%4==3)printf("\n");
	}
	return 0;
		} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c%*c",&a[i/4][i%4]);
   ^