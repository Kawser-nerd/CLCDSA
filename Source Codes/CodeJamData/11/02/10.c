#include <stdio.h>

int testcase(int Ti) {
	char comb[256][256] = {};
	char oppo[256][256] = {};
	char b[200], s[200] = {};
	int i, j, l = 0;
	int C, D, N;
	scanf("%d", &C);
	for(i = 0; i < C; i++) {
		scanf("%s", b);
		comb[b[0]][b[1]] = comb[b[1]][b[0]] = b[2];
	}
	scanf("%d", &D);
	for(i = 0; i < D; i++) {
		scanf("%s", b);
		oppo[b[0]][b[1]] = oppo[b[1]][b[0]] = 1;
	}
	scanf("%d%s", &N, b);
	for(i = 0; i < N; i++) {
		s[l++] = b[i];
		while(l >= 2 && comb[s[l-1]][s[l-2]]) {
			s[l-2] = comb[s[l-1]][s[l-2]];
			s[l-1] = '\0';
			l--;
		}
		for(j = 0; j < l-1; j++)
			if(oppo[s[j]][s[l-1]]) {
				s[l = 0] = '\0';
				break;
			}
	}
	printf("Case #%d: [", Ti);
	for(i = 0; i < l; i++) {
		printf("%s%c", (i > 0 ? ", " : ""), s[i]);
	}
	printf("]\n");
	return 0;
}

int main() {
	int T, i;
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
		testcase(i);
	return 0;
}
