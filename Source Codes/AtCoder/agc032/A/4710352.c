#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void shift_num(int *num) {
	int i = 0;
	while (*(num + i) != -1) {
		*(num + i) = *(num + i + 1);
		i++;
	}
}

int main(void) {
	int n, sw;
	int *num, *answer;
	scanf("%d", &n);
	num = (int *)malloc(sizeof(int)*(n+1));
	answer = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", num + i);
	}
	num[n] = -1;
	for (int i = 0; i < n; i++) {
		sw = FALSE;
		for (int j = n - 1 - i; j >= 0; j--) {
			if (num[j] == j + 1) {
				answer[i] = j + 1;
				shift_num(num + j);
				sw = TRUE;
				break;
			}
		}
		if (sw == FALSE) {
			break;
		}
	}
	if (sw == TRUE) {
		for (int i = n - 1; i >= 0; i--) {
			printf("%d\n", answer[i]);
		}
	}
	else if (sw == FALSE) {
		printf("%d\n", -1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", num + i);
   ^