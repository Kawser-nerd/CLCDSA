#include<stdio.h>

int main() {
	int a,b,c;
	int cnt=0;
	scanf("%d%d",&a,&b);
	c = b;
	while (c != 0) {
		c /= 10;
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		a *= 10;
	}
	int sum = a + b;
	printf("%d\n", sum * 2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^