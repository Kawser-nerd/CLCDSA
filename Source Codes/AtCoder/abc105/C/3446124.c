#include <stdio.h>
int main()
{
	int	n, r;
	char	c[40];
	int	i, j;

	scanf("%d", &n);
	if (n == 0) {
		printf("0\n");
	}
	else {
		j = 0;
		while (n != 0) {
			r = (n % 2)? 1: 0;
			n = (n - r) / -2;
			c[j] = '0' + r;
			j++;
		}
		for (i = j-1; 0 <= i; --i) {
			printf("%c", c[i]);
		}
		printf("\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^