#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long int ulli;

ulli n;
ulli t[10000];
ulli a[10000];

ulli max(ulli a, ulli b) {
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}

ulli main() {
	scanf("%llu", &n);
	for (ulli i = 0; i < n; i++) {
		scanf("%llu %llu", &t[i], &a[i]);
	}

	ulli temp;
	for (ulli i = 1; i < n; i++) {
		temp = max((a[i - 1] + a[i] - 1) / a[i], (t[i - 1] + t[i] - 1) / t[i]);
		a[i] = temp * a[i];
		t[i] = temp * t[i];
	}

	printf("%llu\n", a[n - 1] + t[n - 1]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu", &n);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu %llu", &t[i], &a[i]);
   ^