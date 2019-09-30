#include <stdio.h>

int main(void) {
	int num[3];
	int i, j;
	int diff;
	int answer;
	if (scanf("%d%d%d", &num[0], &num[1], &num[2]) != 3) return 1;
	for (i = 0; i < 3; i++) {
		for (j = 1; j < 3; j++) {
			if (num[j - 1] > num[j]) {
				int t = num[j - 1];
				num[j - 1] = num[j];
				num[j] = t;
			}
		}
	}

	diff = (num[2] - num[1]) + (num[2] - num[0]);
	if (diff % 2 == 0) {
		answer = diff / 2;
	} else {
		answer = (diff + 3) / 2;
	}

	printf("%d\n", answer);
	return 0;
}