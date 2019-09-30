#include <stdio.h>

int main() {
	int n, result = 0, memo = 0;
	char str[105];
	int num[200]={};
	scanf("%d", &n);
	scanf("%s", str);

	for (int i = 0; i < n-1 ; i++) {

		for (int j = 0; j <= i; j++)
		{
			num[str[j]] = 1;
		}

		for (int j = n - 1; j > i; j--)
		{
			if (num[str[j]] >= 1)
			{
				memo++;
				num[str[j]] = 0;
			}
		}

		for (int j = 'a'; j <= 'z'; j++)
		{

			num[j] = 0;
		}
		if (memo > result)
		{
			result = memo;
		}
		memo = 0;
	}
	printf("%d", result);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^