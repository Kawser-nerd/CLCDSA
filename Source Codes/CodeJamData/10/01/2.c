#include <stdio.h>

int main() {
	int tc, cs, n, k;

	scanf("%d", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%d%d", &n, &k);
		printf("Case #%d: %s\n", cs+1, (k+1)%(1<<n) == 0 ? "ON" : "OFF");
	}

	return 0;
}


