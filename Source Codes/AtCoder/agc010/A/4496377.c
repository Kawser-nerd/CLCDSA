#include <stdio.h>

int main()
{
	int n;
	int dat;
	int odd = 0, even = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &dat);

		if (dat & 1) {
			odd++;
		} else {
			even++;
		}
	}

	if (odd & 1) {
		puts("NO");
	} else {
		puts("YES");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &dat);
   ^