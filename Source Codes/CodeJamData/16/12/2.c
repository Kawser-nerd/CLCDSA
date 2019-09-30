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

static void go(int n);

int main(void) {
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++) {
		int n;
		scanf("%d", &n);
		printf("Case #%d:", i);
		go(n);
		printf("\n");
	}
	return 0;
}


static void go(int n){
	int lists[99][50];
	int index[99];
	int at_rank_a[50];
	int at_rank_b[50];
	bool ignore[99] = {0};

	int num_lists = 2*n-1;

	for(int i = 0; i < num_lists; i++){
		for(int j=0; j<n; j++){
			if(scanf("%d", &lists[i][j]) != 1){
				printf("ERROR: BAD READ! %d %d\n",i,j);
				exit(1);
			}
		}
	}

	int missing_pos;
	int pair;
	for(int pos = 0; pos < n; pos++){
		int min = 9999;
		int minlist_a = -1;
		int minlist_b = -1;
		for(int i = 0; i < num_lists; i++) {
			if(ignore[i]) continue;

			int test = lists[i][pos];

			if(test <= min) {
				minlist_b = (test == min) ? minlist_a : -1;
				minlist_a = i;
				min = test;
			}
		}

		//printf("DEBUG: pos %d min %d at %d and %d\n", pos, min, minlist_a, minlist_b);

		at_rank_a[pos] = minlist_a;
		at_rank_b[pos] = minlist_b;

		index[minlist_a] = pos;
		ignore[minlist_a] = true;
		
		if(minlist_b == -1){
			missing_pos = pos;
			pair = minlist_a;
		} else {
			index[minlist_b] = pos;
			ignore[minlist_b] = true;
		}
	}

	int ans_vec[50];

	for(int i = 0; i < n; i++) {
		int ans;
		if(i == missing_pos) {
			ans = lists[pair][missing_pos];
		} else {
			int test = lists[at_rank_a[i]][missing_pos];

			if(test == lists[pair][i]) {
				ans = lists[at_rank_b[i]][missing_pos];
			} else {
				ans = test;
			}
		}

		printf(" %d",ans);

		ans_vec[i] = ans;
	}

	// verify
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int x1 = lists[at_rank_a[i]][j];
			int x2 = lists[at_rank_a[j]][i];
			int x3 = (i == missing_pos) ? ans_vec[j] : lists[at_rank_b[i]][j];
			int x4 = (j == missing_pos) ? ans_vec[i] : lists[at_rank_b[j]][i];
			if(!((x1 == x2 && x3 == x4) || (x1 == x4 && x2 == x3))){
				printf("\nFOUND ISSUE: %d %d %d %d %d %d\n",i,j,x1,x2,x3,x4);
			}
		}
	}
}
