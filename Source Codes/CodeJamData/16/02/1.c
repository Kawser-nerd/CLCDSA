#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

int go(void);

int main(void) {
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d: %d\n", i, go());
	}
	return 0;
}

int go() {
	char c;
	int ans = 0;

	do {
		scanf("%c", &c);
	} while(c != '+' && c != '-');
	bool last_minus = (c == '-');

	do {
		if(scanf("%c", &c) != 1) break;
		bool minus = (c == '-');
		bool plus = (c == '+');
		if(plus || minus) {
			ans += last_minus ^ minus;
			last_minus = minus;
		}
	} while(c != '\n');
	return ans + last_minus;
}
