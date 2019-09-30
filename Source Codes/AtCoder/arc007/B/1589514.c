#include<stdio.h>
#include<stdlib.h>

#define swap(type, a, b) do{type temp = a; a = b; b = temp;}while(0)

int main()
{
	int n, m, i, t = 0;
	int *d;

	scanf("%d%d", &n, &m);
	d = (int *)calloc(n, sizeof(int));
	for(i = 0; i < n; i++)
		d[i] = i + 1;

	for(i = 0; i < m; i++)
	{
		int num, j;

		scanf("%d", &num);

		if(num == t)
			continue;

		for(j = 0; j < n; j++)
			if(d[j] == num)
				break;

		swap(int, t, d[j]);
	}

	for(i = 0; i < n; i++)
		printf("%d\n", d[i]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &m);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &num);
   ^