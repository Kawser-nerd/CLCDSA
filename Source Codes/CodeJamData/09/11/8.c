#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX 1000

int tovet(char s[], int v[]) {
	int i = 0, off;
	char *ptr = s, c;
	for (ptr=s; sscanf(ptr,"%d%c%n",&v[i],&c,&off) == 2; i++,ptr+=off);
	return ++i;
}

char happy[11][MAX];

int calc(int n, int base) {
	int ans = 0;
	while (n) {
		ans += (n % base) * (n % base);
		n /= base;
	}
	return ans;
}

int verify(int n, int base) {
	if (happy[base][n] >= 0) {
		return happy[base][n];
	}
	n = calc(n,base);
	assert(n < MAX);
	if (happy[base][n] == -2) {
		return 0;
	}
	if (happy[base][n] == -1) {
		happy[base][n] = -2;
		happy[base][n] = verify(n,base);
	}
	return happy[base][n];
}

int main() {
	int caso = 1, i, k, t, v[15], n;
	char s[1000];
	
	memset(happy,-1,sizeof(happy));
	for (k=2; k <= 10; k++) {
		happy[k][1] = 1;
		for (i=2; i < MAX; i++) {
			if (happy[k][i] == -1) {
				happy[k][i] = verify(i,k);
			}
		}
	}
	
	scanf("%d\n",&t);
	while (t--) {
		n = tovet(gets(s),v);
		
		for (i=2; 1; i++) {
			for (k=0; k < n; k++) {
				if (!happy[v[k]][calc(i,v[k])]) {
					break;
				}
			}
			if (k == n) {
				break;
			}
		}
		
		printf("Case #%d: %d\n",caso++,i);
	}
	
	return 0;
}
