#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

static void go(int k, int c, int s);

int main(void) {
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++) {
		int k;
		int c;
		int s;
		scanf("%d %d %d", &k, &c, &s);
		printf("Case #%d:", i);
		go(k, c, s);
		printf("\n");
	}
	return 0;
}

static void go(int k, int c, int s){
	if(s*c < k) {
		printf(" IMPOSSIBLE");
		return;
	}

	uint64_t out = 0;
	for(int i = 0; i < k; i++) {
		out = out*k+i;
		if((i+1)%c == 0) {
			printf(" %" PRIu64, out+1);
			out = 0;
		}
	}
	if(k%c != 0){
		printf(" %"PRIu64, out+1);
	}
}
