#include <stdio.h>

int testcase(int Ti) {
	int N, i, in, xor = 0, min = 2000000;
	long long int x = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &in);
		xor ^= in;
		x += in;
		if(in < min) min = in;
	}
	if(xor)
		printf("Case #%d: NO\n", Ti);
	else
		printf("Case #%d: %lld\n", Ti, x - min);
	return 0;
}

int main() {
	int T, i;
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
		testcase(i);
	return 0;
}
