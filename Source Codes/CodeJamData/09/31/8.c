#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char s[65];
long long m[256];
long long base;

void reset() {
	int i;
	
	gets(s);
	
	memset(m, 0, sizeof(m));
	base = 0;
	
	for (i = 0; i<strlen(s); i++) {
		if ( !m[s[i]] ) {
			m[s[i]] = -1;
			base++;
		}
	}
	
	if (base <= 1) base = 2;
}

void solve() {
	int c, i;
	unsigned long long r = 0, b = 1;
	
	c = 0;
	
	for (i=0; i<strlen(s); i++) {
		if (m[s[i]] == -1) {
			m[s[i]] = c++;
		}
	}
	
	for (i=0; i<256; i++) {
		if (m[i] == 0) {
			m[i] = 1;
		} else if (m[i] == 1) {
			m[i] = 0;
		}
	}
	
	for (i=strlen(s)-1; i>=0; i--) {
		r += b * m[s[i]];
		b *= base;
	}
	
	printf("%qd\n", r);
}

void single_case() {
	reset();
	solve();
}

int main()
{
	int c, i;
	
	scanf("%d\n", &c);
	
	for (i=1; i<=c; i++) {
		printf("Case #%d: ", i);
		single_case();
	}
	
	return 0; 
}