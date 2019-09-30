#include <stdio.h>

int main()
{
	char A[101], B[101];
	scanf("%s%s", A, B);
	int i, j, k, flag=0;
	for (i = 0; A[i] != '\0'; i++) {
		;
	}
	for (j = 0; B[j] != '\0'; j++) {
		;
	}
	if (i > j) {
		printf("GREATER\n");
		flag = 1;
	} else if (i < j) {
		printf("LESS\n");
		flag = 1;
	} else {
		for (k = 0; k < i; k++) {
			if (A[k] < B[k]) {
				printf("LESS\n");
				flag=1;
				break;
			} else if (A[k] > B[k]) {
				printf("GREATER\n");
				flag = 1;
				break;
			} 
		}
	} 
	if (flag == 0) {
		printf("EQUAL\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s", A, B);
  ^