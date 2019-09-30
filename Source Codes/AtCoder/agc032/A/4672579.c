#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	int n, b[101], a[101], count;

  if(scanf("%d", &n) == 1);
	count = n;

	for(int i = 1; i <= n; i++) {
		if(scanf("%d", &b[i]) == 1);
	}

	for(int i = n; i > 0; i--) {
		if(i == b[i]) {
			a[n] = i;
			for(int j = i; j < n; j++) {
				b[j] = b[j + 1];
			}
			n--;
			i = n + 1;
		}
	}

	if(n == 0) {
		for(int i = 1; i <= count; i++) {
			printf("%d\n", a[i]);
		}
	} else {
		printf("-1");
	}

  return 0;
}