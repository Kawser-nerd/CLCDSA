#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int jo(int a, int b) {
	int i, j;
	j = a;
	for (i = 1; i < b; i++) {
		a *= j;
	}

	return a;
}

int main() {
	int i, j, k, l, m, n, x;

	scanf("%d",&x);

	m = 1;
	for (i = 2; i <= x; i++) {
		j = 2;
		k = jo(i, j);
		while (k <= x) {
			m = m < k ? k : m;
			j++;
			k = jo(i, j);
		}
	}

	printf("%d", m);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&x);
  ^