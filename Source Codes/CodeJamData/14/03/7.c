#include <stdio.h>

int main() {
	int T;
	int t;
	int R, C, M, N;
	int s, l;
	int i, j;

	char map[50][50];
	int possible;
	scanf("%d", &T);

	for(t = 1; t <= T; t++) {
		possible = 1;
		scanf("%d%d%d", &R, &C, &M);

		N = R * C - M;

		if(R <= C) {
			s = R;
			l = C;
		}
		else {
			s = C;
			l = R;
		}
		switch(s) {
			case 1: {
				for(i = 0;i < l; i++) {
					if(i == 0) map[0][i] = 'c';
					else if(i < N) map[0][i] = '.';
					else map[0][i] = '*';
				}
			}
				break;
			case 2: {
				if(N == 1) {
					for(i = 0; i < s; i++) {
						for(j = 0; j < l ;j++) {
							map[i][j] = '*';
						}
					}
					map[0][0] = 'c';
				}
				else if(N > 2 && N % 2 == 0) {
					for(i = 0; i < s; i++) {
						for(j = 0; j < l; j++) {
							if(j < N/2) {
								map[i][j] = '.';
							}
							else {
								map[i][j] = '*';
							}
						}
					}
					map[0][0] = 'c';
				}
				else {
					possible = 0;
				}
			}
				break;
			default: {
				for(i = 0; i < s; i++)
					for(j = 0; j < l; j++) 
						map[i][j] = '*';
				if( N > 2 * s + 2 ) {
					int k = (N - 2) / s;
					if(N % s == 1) {
						for(i = 0; i < s; i++) {
							for(j = 0; j < l ;j++) {
								if(j < k) {
									map[i][j] = '.';
								}
								else if(j == k && i < s - 1) {
									map[i][j] = '.';
								}
								else if(j == k + 1 && i < 2) {
									map[i][j] = '.';
								}
							}
						}
					}
					else {
						for(i = 0; i < s; i++) {
							for(j = 0; j < l; j++) {
								if(j < k) {
									map[i][j] = '.';
								}
								if(j == k && (i < N % s || N % s == 0)) {
									map[i][j] = '.';
								}
							}
						}
					}
				}
				else if( N > 2 && N % 2 == 0) {
					for(i = 0; i < s; i++) {
						for(j = 0; j < 2; j++) {
							if(i < N / 2) map[i][j] = '.';
						}
					}
				}
				else if( N >= 9 ) {
					for(i = 0; i < s; i++) {
						for(j = 0; j < l ;j++) {
							if(j < 2 && i < (N - 3) / 2)
								map[i][j] = '.';
							if(j == 2 && i < 3)
								map[i][j] = '.';
						}
					}
				}
				else if( N == 4 ) {
					map[0][1] = map[1][0] = map[1][1] = '.';
				}
				else if( N == 1) {
				}
				else {
					possible = 0;
				}
				map[0][0] = 'c';
			}
				break;
		}
		printf("Case #%d:\n", t);
		if(possible) {
			if(s == R) {
				for(i = 0; i < s; i++) {
					for(j = 0; j < l; j++) {
						printf("%c", map[i][j]);
					}
					printf("\n");
				}
			}
			else {

				for(i = 0; i < l; i++) {
					for(j = 0; j < s; j++) {
						printf("%c", map[j][i]);
					}
					printf("\n");
				}
			}
		}
		else 
			printf("Impossible\n");
	}


}
