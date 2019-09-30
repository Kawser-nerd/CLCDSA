#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}

int main(void){
	int n;
	int *data;
	int sign = 1;
	int sum = 0;
	scanf("%d", &n);
	data = malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)
		scanf("%d", data + i);
	qsort(data, n, sizeof(int), cmp);
	for(int i = 0; i < n; i++){
		sum += sign * data[i] * data[i];
		sign = -sign;
	}
	printf("%.15f\n", M_PI * sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", data + i);
   ^