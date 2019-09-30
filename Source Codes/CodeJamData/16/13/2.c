#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char* get_line(void) {
	int bufsize = 1;
	int len = 0;
	char* ans = malloc(bufsize);
	while(1){
		char c;
		int read_bytes = scanf("%c", &c);
		if(read_bytes != 1) {
			printf("READ FAILURE, errno=%d (%s)\n", errno, strerror(errno));
			exit(1);
		}
		switch(c) {
		case '\n': 
			if(len == 0) continue;
			ans[len] = '\0';
			return ans;
		case '\r':
			break;
		default:
			ans[len++]=c;
			if(len == bufsize) {
				bufsize *= 2;
				ans = realloc(ans, bufsize);
				if(ans == NULL) {
					printf("OUT OF MEMORY FOR READ\n");
					exit(1);
				}
			}
		}
	}
}

static int go(int n);

int main(void) {
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", i, go(n));
	}
	return 0;
}

int bff[1000];

static int cycle_test(int start) {
	bool used[1000] = {0};
	int curr = start;
	int ans = 1;
	while(1){
		used[curr] = true;
		int next = bff[curr];
		if(next == start) {
			return ans;
		}
		if(used[next]){
			return 1;
		}
		curr = bff[curr];
		ans++;
	}
}

static int chain_test(int start, int* end_pair) {
	bool used[1000] = {0};
	int curr = start;
	int prev = -1;
	int ans = 0;
	while(1){
		used[curr] = true;
		int next = bff[curr];
		if(next == prev) {
			*end_pair = curr;
			return ans;
		}
		if(used[next]){
			return 0;
		}
		prev = curr;
		curr = bff[curr];
		ans++;
	}
}

static int go(int n){
	int best_chain_to[1000] = {0};

	for(int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		bff[i] = t-1;
	}

	int best = 1;

	for(int start = 0; start < n; start++){
		int t = cycle_test(start);
		if(t > best) best=t;
	}

	for(int start = 0; start < n; start++){
		int p;
		int t = chain_test(start, &p);
		if(t != 0){
			if(best_chain_to[p] < t) best_chain_to[p] = t;
		}
	}

	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += best_chain_to[i];
	}
	if(sum > best) best=sum;

	return best;
}
