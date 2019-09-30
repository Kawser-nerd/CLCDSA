#include<stdio.h>
#include<stdlib.h>
int main() {
	int A, B, ans = 0,N;
	scanf("%d %d", &A, &B);
	N = abs(A - B);
	if (A == B) {
		printf("0\n");
		return 0;
	}

	while (N >= 10) {
		ans++;
		N -= 10;
	}

	switch (N) {
	case 9:
	case 6:
	case 4:
	case 2:
		ans += 2;
		break;
	case 8:
	case 7:
	case 3:
		ans += 3;
		break;
	case 5:
	case 1:
		ans++;
		break;
	default :
		break;
	}

	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &A, &B);
  ^