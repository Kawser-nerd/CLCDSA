#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, *l, i, max, sum;

	scanf("%d", &n);

	if ((l = (int *)malloc(sizeof(int) * n)) == NULL)
		return 1;

	for (i = 0; i < n; i++)
		scanf("%d", l + i);

	for (i = 0, max = l[0], sum = 0; i < n; i++) {
		if (l[i] > max)
			max = l[i];
		sum += l[i];
	}

	if (max < sum - max)
		printf("Yes\n");
	else
		printf("No\n");

	free(l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", l + i);
   ^