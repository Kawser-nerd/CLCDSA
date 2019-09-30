#include <stdio.h>

int main(void) {
	int i, index = 0, n, ans[200000], f;
	scanf("%d", &n);
	if (n % 2 == 0) 
		f = 1;
	else
		f = -1;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0)
			index = index + i * f;
		else
			index = index - i * f;
		scanf("%d", &ans[n / 2 + index]);
	}
	for (i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &ans[n / 2 + index]);
   ^