#include <stdio.h>

int main() {
	int t, T, n, i, in;
	int a[10];
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d", &n);
		printf("Case #%d: ", t);
		if (n == 0) {
			printf("INSOMNIA\n");
		} else {
			for (i = 0; i < 10; i++) a[i] = 0;
			i = 0;
			while (a[0]*a[1]*a[2]*a[3]*a[4]*a[5]*a[6]*a[7]*a[8]*a[9] == 0) {
				i++;
				in = i * n;
				while(in > 0) {
					a[in % 10] = 1;
					in /= 10;
				}
			}
			printf("%d\n", i * n);
		}
	}
}
