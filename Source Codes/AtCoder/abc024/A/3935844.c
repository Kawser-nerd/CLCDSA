#include <stdio.h>

int main(){
	int a, b, c, k, s, t, sum;
	scanf("%d %d %d %d", &a, &b, &c, &k);
	scanf("%d %d", &s, &t);
	if(s + t >= k){
		a -= c;
		b -= c;
	}
	sum = a * s + b * t;
	printf("%d\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &a, &b, &c, &k);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &s, &t);
  ^