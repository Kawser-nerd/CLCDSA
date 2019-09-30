#include <stdio.h>
#include <string.h>
#include <float.h>

char str[8];
int n;
double x;
double sum;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lf %s", &x, str);

		if (strcmp(str, "JPY") == 0) {
			sum = sum + x;
		} else {
			sum = sum + x * 380000;
		}
	}

	printf("%lf\n", sum);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %s", &x, str);
   ^