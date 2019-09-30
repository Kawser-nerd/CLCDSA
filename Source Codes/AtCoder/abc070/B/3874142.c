#include<stdio.h>

int main() {
	int a,b,c,d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int i,j, sum = 0;
	for(i = a; i < b; ++i) {
		for(j = c; j < d; ++j) {
			if(i == j) sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &a, &b, &c, &d);
  ^