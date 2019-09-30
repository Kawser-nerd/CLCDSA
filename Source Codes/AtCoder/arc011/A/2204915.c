/*
AtCoder Regular Contest 011 A - ??????????? Ver1 ??:
*/

#include <stdio.h>

#define DEBUG1

int main() {

	int a, b, n;
	int y = 0;

	scanf("%d %d %d", &a, &b, &n);
	
	for (y=n; a<=n; y+=b) {
		n-=a-b;
	}

	printf("%d\n", y);

	//getch();
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &a, &b, &n);
  ^