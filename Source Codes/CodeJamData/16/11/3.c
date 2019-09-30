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

static void go(const char* s);

int main(void) {
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++) {
		char* in = get_line();
		printf("Case #%d: ", i);
		go(in);
		free(in);
		printf("\n");
	}
	return 0;
}

static int getbest(const char* s, int a, int b){
	if(b<=a) return -1;
	int ans = a;
	for(int i=a+1; i<b; i++) {
		if(s[i] >= s[ans]) {
			ans = i;
		}
	}
	return ans;
}

static void go(const char* s){
	int n = strlen(s);
	int* bestpos = (int*)malloc(sizeof(int)*(n+1)*(n+1));
	for(int i = 0; i<=n; i++){
		for(int j=0; j<=n; j++){
			bestpos[i*(n+1)+j] = getbest(s,i,j);
		}
	}

	bool* used = (bool*)calloc(n, sizeof(bool));

	int pos = n;
	while(pos>0) {
		int nextpos = bestpos[pos];
		printf("%c", s[nextpos]);
		used[nextpos] = true;
		pos = nextpos;
	}

	for(int i = 0; i < n; i++) {
		if(!used[i]) printf("%c", s[i]);
	}
}
