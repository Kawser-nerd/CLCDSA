#include <stdio.h>
#include <math.h>

int main(void){
	long n;
	scanf("%ld", &n);
	printf("%ld\n", (int)sqrt(sqrt(n)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘int’ [-Wformat=]
  printf("%ld\n", (int)sqrt(sqrt(n)));
         ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &n);
  ^