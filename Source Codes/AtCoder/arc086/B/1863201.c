#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
	int n;
	int i, max_i, min_i;
	int a[50];
	int max = INT_MIN, min = INT_MAX;
	int cs;
	int cnt;
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		scanf("%d", a + i);
		if (a[i] > max){
			max = a[i];
			max_i = i;
		}
		if (a[i] < min){
			min = a[i];
			min_i = i;
		}
	}
	//	printf("%d\n", n * 2);
	if (max <= 0){
		//all negative
		printf("%d\n", n - 1);
		for (i = 0; i < n - 1; ++i){
			printf("%d %d\n", n - i, n - i - 1);
		}
	}
	else if (min >= 0){
		//all positive
		printf("%d\n", n - 1);
		for (i = 0; i < n - 1; ++i){
			printf("%d %d\n", i + 1, i + 2);
		}
	}
	else if (-max < min){
		printf("%d\n", n + n - 1);
		for (i = 0; i < n; ++i){
			printf("%d %d\n", max_i + 1, i + 1);
		}
		for (i = 0; i < n - 1; ++i){
			printf("%d %d\n", i + 1, i + 2);
		}
	}
	else{
		printf("%d\n", n + n - 1);
		for (i = 0; i < n; ++i){
			printf("%d %d\n", min_i + 1, i + 1);
		}
		for (i = 0; i < n - 1; ++i){
			printf("%d %d\n", n - i, n - i - 1);
		}
	}
	//	printf("%s\n", s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", a + i);
   ^