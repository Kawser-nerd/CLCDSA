#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}

int calc(int *array, int *l, int *a, int n){
	int cost = 0;
	for(int i = 0; i < 3; i++){
		int count = 0;
		int sum = 0;
		for(int j = 0; j < n; j++){
			if(array[j] == i){
				count++;
				sum += l[j];
			}
		}
		if(count == 0)return 10000;
		cost += (count - 1) * 10 + abs(sum - a[i]);
	}
	return cost;
}

int try(int *array, int p, int *l, int *a, int n){
	if(p == n){
		return calc(array, l, a, n);
	}
	int min = 10000;
	for(int i = 0; i < 4; i++){
		array[p] = i;
		int tmp = try(array, p + 1, l, a, n);
		if(tmp < min)min = tmp;
	}
	return min;
}

int main(void){
	int n, a[3];
	int l[10];
	int chk[10];

	scanf("%d %d %d %d", &n, a, a + 1, a + 2);
	for(int i = 0; i < n; i++)
		scanf("%d", l + i);
	qsort(l, n, sizeof(int), comp);
	printf("%d\n", try(chk, 0, l, a, n));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:43:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &n, a, a + 1, a + 2);
  ^
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", l + i);
   ^