#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	int num, size;
	int *values;
	scanf("%d", &num);
	size = num * 10;
	values = (int *)malloc(size * sizeof(int));
	//memset(cnt, 0, num * sizeof(int));

	// ????
	int i = 0;
	//char buff[100];
	//fgets(buff, sizeof(buff), stdin);
	//if (sscanf(buff, "%d", &num[i]) != 1)
	for (i = 0;; ++i)
	{
		if (size <= i)
		{
			void* w = malloc(size * 2 * sizeof(int));
			memcpy(w, values, size);
			free(values);
			values = (int*)w;
			size *= 2;
		}
		scanf("%d", &values[i]);
		char chr;
		chr = getchar();
		if(chr == '\n' || chr == EOF)
			break;
	}
	// ??
	qsort(values, i+1, sizeof(int), compare);

	// ?
	int sum = 0;
	for (i = 0; i < num; ++i)
	{
		sum += values[i*2 + 1];
	}
	// ??
	printf("%d\n", sum);
	free(values);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &num);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &values[i]);
   ^