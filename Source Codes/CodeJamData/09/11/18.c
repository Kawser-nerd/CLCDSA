#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char cache[11][100001];

void init_data() {
	int b;
	
	memset(cache, -1, sizeof(cache));
	
	for (b=2; b<=10; b++) {
		cache[b][1] = 1;
	}
}

int next_number(int base, int n10) {
	int digits[33], i, p, r;
	
	p = i = 0;
	
	while (n10 > 0) {
		digits[p++] = n10 % base;
		n10 /= base;
	}
	
	r=0;
	
	for (i=0; i<p; i++) {
		r += digits[i] * digits[i];
	}

	return r;
}

int check_number(int base, int n10, int depth) {
	if (depth > 11111*base) {
		return 0;
	}
	
	if (n10 <= 100000) {
		if (cache[base][n10] != -1) {
			return cache[base][n10];
		} else {
			return (cache[base][n10] = check_number(base, next_number(base, n10), depth+1));
		}
	} else {
		while (n10 > 100000) {
			n10 = next_number(base, n10);
		}
		
		return check_number(base, n10, depth+10);
	}
}

void single_case() {
	int bases[10], p, i, ans, flag;
	char c;
	
	p = 0;
	ans = 2;
	
	do {
		scanf("%d%c", &bases[p++], &c);
	} while ( c == ' ' );
	
	while (ans <= 100000) {
		flag = 1;
				
		for (i=0; i<p; i++ && flag) {
			flag = flag && check_number(bases[i], ans, 0);
		}
		
		if (flag) {
			break;
		}
		
		ans++;
	}
	
	printf("%d\n", ans);
}

void pre_cache() {
	int i, j;
	
	for (i=2; i<=10; i++) {
		for (j=0; j<=10000; j++) {
			check_number(i, j, 0);
		}
	}
}

int main() {
	int cases, i;
	
	init_data();
	//pre_cache();

	scanf("%d\n", &cases);
	
	for (i=1; i<=cases; i++) {
		printf("Case #%d: ", i);
		single_case();
	}
	
	return 0;
}