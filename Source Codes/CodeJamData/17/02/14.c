#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char N[32];
char R[32];
char Z[32];

void set(char *ptr, int i, char c) {
	for (; ptr[i]; ++i)
		ptr[i] = c;
}

void solve(int digits) {
	memset(R, '1', sizeof(R));
	R[digits] = '\0';
	unsigned long long int n = strtoull(N, NULL, 10);
	unsigned long long int r = strtoull(R, NULL, 10);
	for (int i = 0; R[i]; ++i) {
		memcpy(Z, R, sizeof(R));
		for (char d = '2'; d <= '9'; d++) {
			set(Z, i, d);
			long long int z = strtoull(Z, NULL, 10);
			if (z > n)
				break;
			memcpy(R, Z, sizeof(R));
		}
	}
	r = atoll(R);
	if (r > n)
		solve(digits-1);
}

int main() {
	int i, n, t, x = 1;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%s%n\n", N, &n);
		solve(n);
		printf("Case #%d: %s\n", x++, R);
	}
}
