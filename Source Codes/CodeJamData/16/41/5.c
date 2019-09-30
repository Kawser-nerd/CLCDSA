#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

static char* get_line(void) {
	int bufsize = 1;
	int len = 0;
	char* ans = malloc(bufsize);
	while(1){
		char c;
		ssize_t read_bytes = read(0, &c, 1);
		if(read_bytes != 1) {
			printf("READ FAILURE, errno=%d (%s)\n", errno, strerror(errno));
			exit(1);
		}
		switch(c) {
		case '\n': 
			ans[len] = '\0';
			return ans;
		case '\r':
			continue;
		default:
			len++;
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

static void go(int n, int r, int p, int s);

int main(void) {
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++) {
		int n;
		int r;
		int p;
		int s;
		scanf("%d %d %d %d", &n, &r, &p, &s);
		printf("Case #%d: ", i);
		go(n, r, p, s);
		printf("\n");
	}
	return 0;
}

#define P_MASK 1
#define R_MASK 2
#define S_MASK 4

// best groups of 2: PR, PS, RS

// every group of four is
//  PRPS (S), PRRS (P), PSRS (R)
//
// every group of 8 is 

static bool valid(int n, char* str, int r, int p, int s) {
	for(int i = 0; i < (1 << n); i++) {
		switch(str[i]) {
		case 'R': r--; break;
		case 'P': p--; break;
		case 'S': s--; break;
		}
	}
	
	return r == 0 && p == 0 && s == 0;
}

static void go(int n, int r, int p, int s){
	char* currp;
	char* currr;
	char* currs;
	char* nextp;
	char* nextr;
	char* nexts;

	char* buf;

	buf = (char*)malloc(4);
	buf[0] = 'P';
	buf[1] = 'R';
	buf[2] = 'S';

	currp = &buf[0];
	currr = &buf[1];
	currs = &buf[2];

	for(int i = 0; i < n; i++) {
		char* nextbuf = (char*)malloc((6 << i)+1);
		nextp = &nextbuf[0];
		nextr = &nextbuf[2 << i];
		nexts = &nextbuf[4 << i];

		int test;

		test = memcmp(currp, currr, 1 << i);
		if(test < 0) {
			memcpy(&nextp[0],      currp, 1 << i);
			memcpy(&nextp[1 << i], currr, 1 << i);
		} else {
			memcpy(&nextp[0],      currr, 1 << i);
			memcpy(&nextp[1 << i], currp, 1 << i);
		}

		test = memcmp(currr, currs, 1 << i);
		if(test < 0) {
			memcpy(&nextr[0],      currr, 1 << i);
			memcpy(&nextr[1 << i], currs, 1 << i);
		} else {
			memcpy(&nextr[0],      currs, 1 << i);
			memcpy(&nextr[1 << i], currr, 1 << i);
		}

		test = memcmp(currp, currs, 1 << i);
		if(test < 0) {
			memcpy(&nexts[0],      currp, 1 << i);
			memcpy(&nexts[1 << i], currs, 1 << i);
		} else {
			memcpy(&nexts[0],      currs, 1 << i);
			memcpy(&nexts[1 << i], currp, 1 << i);
		}

		currp = nextp;
		currr = nextr;
		currs = nexts;

		free(buf);
		buf = nextbuf;
	}

	bool pgood = valid(n, currp, r, p, s);
	bool rgood = valid(n, currr, r, p, s);
	bool sgood = valid(n, currs, r, p, s);

	int comp_pr = memcmp(currp, currr, 1 << n);
	int comp_rs = memcmp(currr, currs, 1 << n);
	int comp_ps = memcmp(currp, currs, 1 << n);

	if(!pgood) {
		comp_pr = -1;
		comp_ps = -1;
	}

	if(!rgood) {
		comp_pr = 1;
		comp_rs = -1;
	}

	if(!sgood) {
		comp_rs = 1;
		comp_ps = 1;
	}

	

	if(pgood && comp_pr >= 0 && comp_ps >= 0) {
		currp[1 << n] = '\0';
		printf("%s", currp);
		return;
	}

	if(rgood && comp_pr <= 0 && comp_rs >= 0) {
		currr[1 << n] = '\0';
		printf("%s", currr);
		return;
	}

	if(sgood && comp_ps <= 0 && comp_rs <= 0) {
		currs[1 << n] = '\0';
		printf("%s", currs);
		return;
	}

	printf("IMPOSSIBLE");
}
