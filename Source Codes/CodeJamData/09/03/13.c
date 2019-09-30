#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 500
#define BANNER_LEN 19

const unsigned char banner[] = "welcome to code jam";
unsigned char str[MAX_STRLEN+1];
int len; // Actual length of str
int opt[256];
unsigned long dp[BANNER_LEN][MAX_STRLEN]; 

void init_data() {
	int i;

	memset(dp, 0, sizeof(dp));
	memset(str, 0, sizeof(str));
	len = 0;

	memset(opt, 0, sizeof(opt));
	
	for (i=0; i<BANNER_LEN; i++) {
		opt[banner[i]] = 1; 
	}
}

// Return 1 if the string is quick judged.
int read_data() {
	int p, l, i;
	unsigned char s[MAX_STRLEN+1];
	
	init_data();
	
	gets(s);
	l = strlen(s);
	p = 0;
	
	while ( (p < l) && (s[p] != 'w') ) {
		p++;
	}
	
	for (i=p; i<l; i++) {
		if (opt[s[i]]) {
			str[len++] = s[i];
			opt[s[i]] = 2;
		}
	}
	
	if (len < BANNER_LEN) { // shorter than banner, no way to match.
		return 1;
	}
	
	for (i=0; i<256; i++) {
		if (opt[i] == 1) { // missing character, no way to match.
			return 1;
		}
	}
	
	return 0;
}

int solve() {
	int i, j, k, c;
	
	// the first letter: w
	for (j=0; j<len; j++) { // str; assume i = 0;
		if ('w' == str[j]) {
			dp[0][j] = 1;
		}
	}
	
	// the rest
	for (i=1; i<BANNER_LEN; i++) {
		for (j=i; j<len; j++) { // str
			if ( banner[i] == str[j] ) {
				c = 0;
				
				for (k=i-1; k<j; k++) {
					c = (c + dp[i-1][k]) % 10000;
				}
				
				dp[i][j] = c;
			}
		}
	}
	/*
	printf("  ");
	for (j=0; j<len; j++) {
		printf("%5c", str[j]);
	}
	printf("\n");
	for (i=0; i<BANNER_LEN; i++) {
		printf("%c:", banner[i]);
		for (j=0; j<len; j++) {
			if (dp[i][j] != 0) {
				printf("%5d", dp[i][j]);
			} else {
				printf("     ");
			}
		}
		printf("\n");
	}
	*/
	// output
	c = 0;
	
	for (i=0; i<len; i++) { // last character
		c = (c + dp[BANNER_LEN-1][i]) % 10000;
	}
	
	return c;
}

int main() {
	int i, test_cases;
	
	scanf("%d\n", &test_cases);
	
	for (i=1; i<=test_cases; i++) {
		if ( read_data() ) {
			printf("Case #%d: 0000\n", i);
			continue;
		}
		
		printf("Case #%d: %04d\n", i, solve());
	}
	
	return 0; 
}