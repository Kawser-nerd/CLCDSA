#include <stdio.h>
#define MAX 66

int code[256];

int main() {
	long long sum;
	int t, T, i, last;
	char str[MAX];
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%s", str);
		for(i = 0; i < 256; i++)
			code[i] = -1;
		code[str[0]] = 1;
		last = 0;
		for(i = 1; str[i]; i++)
			if(code[str[i]] == -1) {
				code[str[i]] = last++;
				if(last == 1)
					last++;
			}
		if(last < 2)
			last = 2;
		sum = 0;
		for(i = 0; str[i]; i++)
			sum = sum * last + code[str[i]];
		printf("Case #%d: %lld\n", t, sum);
	}
	return 0;
}