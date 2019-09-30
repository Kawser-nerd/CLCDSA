#include <stdio.h>

#define div ((unsigned long)((1e+9) + 7))
int main(void){
	unsigned long in;
	unsigned long res = 1;
	for(int i = 0; i < 3; i++){
		scanf("%ld", &in);
		res *= in % div;
		res %= div;
	}
	printf("%ld\n", res % div);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &in);
   ^