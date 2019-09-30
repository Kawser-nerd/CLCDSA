#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i, j, k;
	int count=0;
	if (n % 2 == 0) {
		while (n != 1) {
			n = n / 2;
			count++;
		}
    printf("%d\n", count);
    for (i = 0; i < count; i++) {
        printf("2\n");
    }
	} else {
		while (n != 1) {
			n = n / 2;
			count++;
		}
		count++;
		printf("%d\n", count);
		printf("1\n");
		for (i = 0; i < count-1; i++) {
			printf("2\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^