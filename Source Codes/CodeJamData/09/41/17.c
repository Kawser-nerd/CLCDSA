#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int caso = 1, t, n, i, j, k, pos[50], v[50], ans;
	char m[50][50];
	
	scanf("%d",&t);
	while (t--) {
		scanf("%d\n",&n);
		
		memset(pos,-1,sizeof(pos));
		
		for (i=0; i < n; i++) {
			gets(m[i]);
			for (j=n-1; m[i][j] == '0'; j--);
			for (k=j; pos[k] != -1; k++);
			pos[k] = i;
			v[i] = i;
		}
		
		ans = 0;
		for (i=n-1; i > 0; i--) {
			for(j=0; v[j] != pos[i]; j++);
			for ( ; j < i; j++) {
				k = v[j], v[j] = v[j+1], v[j+1] = k;
				ans++;
			}
		}
		
		printf("Case #%d: %d\n",caso++,ans);
	}
	
	return 0;
}
