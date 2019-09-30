#include <stdio.h>

int main(int argc, char** arcv) {
	int n = 0, m = 0, tmp = 0, res = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	tmp= m / n;
	for (int i = tmp; 0 < i; i--) {
		if (!(m % i)) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &m);
  ^