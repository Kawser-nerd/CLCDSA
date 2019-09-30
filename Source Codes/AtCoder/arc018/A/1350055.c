#include <stdio.h>
#include <math.h>

int main() {
	float fa, fb, ret;

	scanf("%f" "%f", &fa, &fb);

	ret=pow(fa/100,2)*fb;

	printf("%f\n", ret);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%f" "%f", &fa, &fb);
  ^