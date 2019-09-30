#include <stdio.h>
#include <stdlib.h>

long long power(a, b) {
	if (b == 0) {
		return 1;
	}
	return a * power(a, b - 1);
}

int main() {
	
	int num;
	scanf("%d\n", &num);

	int count = 0;
	int k, c, s;
	int ki;
	long long sum;

	while (count < num) {
		scanf("%d %d %d\n", &k, &c, &s);
		count ++;
		sum = 0;
		printf("Case #%d:", count);
		if (s * c < k) {
			printf(" IMPOSSIBLE\n");
		}
		else {
			ki = 0;
			while (ki < k) {
				if (!(ki % c) && ki) {
					printf(" %lld", sum + 1);
					sum = 0;
				}
				sum = sum + ki * power(k, (c - 1) - (ki % c));
				ki ++;
			}
			printf(" %lld", sum + 1);
			printf("\n");
		}
	}
}
