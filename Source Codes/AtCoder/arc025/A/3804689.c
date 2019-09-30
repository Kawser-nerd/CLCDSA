#include <stdio.h>

int max(int a, int b)
{
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int main()
{
	int d[7];
	int j[7];
	int a, b, sum = 0;
	for (a = 0; a < 7; a++) {
		scanf("%d", &d[a]);
	}
	for (a = 0; a < 7; a++) {
		scanf("%d", &j[a]);
	}
	for (a = 0; a < 7; a++) {
		sum += max(d[a], j[a]);
	}
	printf("%d\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &d[a]);
   ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &j[a]);
   ^