#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int N, T, i, a, old, out = 0;
	scanf("%d%d", &N, &T);
	for (i=0; i < N ;i++) {
		scanf("%d", &a);
		if (i != 0) {
			if (a-old < T) out += a-old;
			else out += T;
		}
		old = a;
	}
	out += T;
	printf("%d\n", out);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &T);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^