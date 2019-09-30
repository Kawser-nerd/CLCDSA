#include<stdio.h>
#include<string.h>
int main(void) {
	int a, b,c,i;
	char A[4];

	scanf("%d %d", &a, &b);

	if  (b == 100){
		c = a * 1000 + b;
	}
	else if (b >= 10) {
		c = a * 100 + b;
	}
	else {
	c = a * 10 + b; 
	}

	for (i = 1; i < c; i++) {
		if (c%i == 0) {
			if (c / i == i) {
				strcpy(A, "Yes"); break;
			}
		}
		strcpy(A, "No"); 
	}

	printf("%s", A);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &a, &b);
  ^