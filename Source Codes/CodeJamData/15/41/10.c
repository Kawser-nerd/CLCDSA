#include <stdio.h>
#include <stdlib.h>

int main() {
	int t, T;
	int R, C;
	int a;
	int i, j, k;
	int imp;
	int flag;
	int g[100][100];
	int rcnt[100];
	int ccnt[100];
	char buf[101];
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d %d", &R, &C);
		for(i = 0; i < R; i++) rcnt[i] = 0;
		for(i = 0; i < C; i++) ccnt[i] = 0;
		a = 0;
		imp = 0;
		for(i = 0; i < R; i++) {
			scanf("%s", buf);
			for(j = 0; j < C; j++) {
				switch(buf[j]) {
					case '.':
						g[i][j] = 0;
						break;
					case '^':
						g[i][j] = 1;
						rcnt[i]++;
						ccnt[j]++;
						break;
					case '>':
						g[i][j] = 2;
						rcnt[i]++;
						ccnt[j]++;
						break;
					case 'v':
						g[i][j] = 3;
						rcnt[i]++;
						ccnt[j]++;
						break;
					case '<':
						g[i][j] = 4;
						rcnt[i]++;
						ccnt[j]++;
						break;
					default:
						g[i][j] = 0;
				}
			}
		}
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(g[i][j] > 0) {
					if(rcnt[i] == 1 && ccnt[j] == 1) {
						imp = 1;
						break;
					}
					flag = 0;
					switch(g[i][j]) {
						case 1:
							for(k = 0; k < i; k++) {
								if(g[k][j] > 0) {
									flag = 1;
									break;
								}
							}
							if(!flag) a++;
							break;
						case 2:
							for(k = C-1; k > j; k--) {
								if(g[i][k] > 0) {
									flag = 1;
									break;
								}
							}
							if(!flag) a++;
							break;
						case 3:
							for(k = R-1; k > i; k--) {
								if(g[k][j] > 0) {
									flag = 1;
									break;
								}
							}
							if(!flag) a++;
							break;
						case 4:
							for(k = 0; k < j; k++) {
								if(g[i][k] > 0) {
									flag = 1;
									break;
								}
							}
							if(!flag) a++;
							break;
					}
				}
			}
			if(imp) break;
		}

		if (imp) {
			printf("Case #%d: IMPOSSIBLE\n", t);
		} else {
			printf("Case #%d: %d\n", t, a);
		}
	}
	return 0;
}
