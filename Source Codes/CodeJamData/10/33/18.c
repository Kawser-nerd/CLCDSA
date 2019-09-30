#include <stdio.h>
#include <string.h>

#define MAX 35
#define min(a,b) (((a) < (b)) ? (a) : (b))

typedef struct {
	int n, c;
} Ans;

char M[MAX][MAX], s[150];
int acc[MAX][MAX], accv[MAX][MAX];
int n, m;

long long toint(char s[]) {
	int val[256], i;
	long long ans = 0;
	
	for (i=0; i < 10; i++) {
		val['0'+i] = i;
		if (i < 6) {
			val['A'+i] = 10 + i;
		}
	}
	
	for (i=0; s[i]; i++) {
		ans = ans*16 + val[(int)s[i]];
	}
	
	return ans;
}

void torow(long long v, int r) {
	int j;
	for (j=0; j < m; j++) {
		M[r][j] = !!(v & (1ll << (m-j-1)));
	}
}

int main() {
	int t, caso = 1;
	Ans list[MAX];
	int qtde, i, j, k, best, count, di, dj;
	
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d\n",&n,&m);
		for (i=0; i < n; i++) {
			gets(s);
			torow(toint(s),i);
		}
		
		qtde = 0;
		while (1) {
			
			acc[0][0] = M[0][0] != -1;
			for (j=1; j < m; j++) {
				if (M[0][j] == -1) {
					acc[0][j] = 0;
				}
				else if (M[0][j-1] == M[0][j] || M[0][j-1] == -1) {
					acc[0][j] = 1;
				}
				else {
					acc[0][j] = acc[0][j-1] + 1;
				}
			}
			for (i=0; i < n; i++) {
				acc[i][0] = M[i][0] != -1;
				for (j=1; j < m; j++) {
					if (M[i][j] == -1) {
						acc[i][j] = 0;
					}
					else if (M[i][j-1] == M[i][j] || M[i][j-1] == -1) {
						acc[i][j] = 1;
					}
					else {
						acc[i][j] = acc[i][j-1] + 1;
					}
				}
			}
			
			for (j=0; j < m; j++) {
				accv[0][j] = !!acc[0][j];
			}
			for (i=1; i < n; i++) {
				for (j=0; j < m; j++) {
					if (M[i][j] == -1) {
						accv[i][j] = 0;
					}
					else if (M[i][j] == M[i-1][j]) {
						accv[i][j] = 1;
					}
					else {
						best = acc[i][j];
						for (k=i-1; k >= 0 && acc[k][j] > i-k && i-k < best && i-k <= accv[i-1][j]; k--) {
							if (acc[k][j] < best) {
								best = acc[k][j];
							}
						}
						accv[i][j] = i - k;
					}
				}
			}
			
			best = 1;
			for (i=0; i < n; i++) {
				for (j=0; j < m; j++) {
					if (accv[i][j] > best) {
						best = accv[i][j];
					}
				}
			}
			
			count = 0;
			for (i=0; i < n; i++) {
				for (j=0; j < m; j++) {
					if (accv[i][j] == best && M[i-best+1][j-best+1] != -1 && M[i-best+1][j] != -1 && M[i][j-best+1] != -1) {
						count++;
						for (di=0; di < best; di++) {
							for (dj=0; dj < best; dj++) {
								M[i-di][j-dj] = -1;
							}
						}
					}
				}
			}
			
			if (count > 0) {
				list[qtde].n = best;
				list[qtde].c = count;
				qtde++;
			}
			
			if (best == 1) {
				break;
			}
		}
		
		printf("Case #%d: %d\n",caso++,qtde);
		for (i=0; i < qtde; i++) {
			printf("%d %d\n",list[i].n,list[i].c);
		}
	}
	
	return 0;
}
