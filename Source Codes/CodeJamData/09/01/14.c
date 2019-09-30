#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 15 // LENGTH
#define MAX_D 5000 // DICTIONARY
#define MAX_N 500 // TEST CASES
#define L_ALPHABET 26

int L, D, N;
char dictionary[MAX_D][MAX_L+1];
char pattern[MAX_N][MAX_L][L_ALPHABET];
int count[MAX_N]; 

void register_pattern(int n, char* s_pat) {
	int i, l, p, flag = 0;
	
	l = strlen(s_pat);
	p = 0;
	flag = 0;
	
	for (i=0; i<l; i++) {
		if (flag == 0) {
			if (s_pat[i] == '(') {
				flag = 1;
			} else {
				pattern[n][p++][s_pat[i]-'a'] = 1;
			}
		} else {
			if (s_pat[i] == ')') {
				flag = 0;
				p++;
			} else {
				pattern[n][p][s_pat[i]-'a'] = 1;
			}
		}
	}
} 

void read_data() {
	int i;
	char line[512];
	
	memset(line, 0, sizeof(line));
	memset(dictionary, 0, sizeof(dictionary));
	memset(pattern, 0, sizeof(pattern));
	memset(count, 0, sizeof(count));
	
	scanf("%d %d %d\n", &L, &D, &N);
	
	for (i=0; i<D; i++) {
		gets(dictionary[i]);
	}
	
	for (i=0; i<N; i++) {
		gets(line);
		register_pattern(i, line);
	}
}

// match dictionary against pattern.
void single_case(char* dic) {
	int i, j;
	
	for (i=0; i<N; i++) {
		for (j=0; j<L; j++) {
			if ( !pattern[i][j][dic[j]-'a'] ) {
				break;
			}
		}
		
		if (j == L) {
			count[i]++;
		}
	}
}

void solve() {
	int i;
	
	for (i=0; i<D; i++) {
		single_case(dictionary[i]);
	}
}

void output() {
	int i;
	
	for (i=0; i<N; i++) {
		printf("Case #%d: %d\n", i+1, count[i]);
	}
}

int main() {
	
	read_data();
	solve();
	output();
	
	return 0;
}