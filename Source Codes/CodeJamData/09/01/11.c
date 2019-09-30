#include <stdio.h>
#include <assert.h>

int main() {
	char patt[30][30], s[1000], dict[5005][30];
	int len[30];
	int l, d, n, i, j, ans, k, x;
	
	scanf("%d %d %d\n",&l,&d,&n);
	
	for (i=0; i < d; i++)
		gets(dict[i]);
	
	for (i=0; i < n; i++) {
		gets(s);
		
		for (j=k=0; s[j]; j++,k++) {
			if (s[j] == '(') {
				len[k] = 0;
				while (s[++j] != ')') {
					patt[k][len[k]++] = s[j];
				}
			}
			else {
				patt[k][0] = s[j];
				len[k] = 1;
			}
		}
		
		assert(k == l);
		
		for (x=ans=0; x < d; x++) {
			for (j=0; j < l; j++) {
				for (k=0; k < len[j]; k++) {
					if (dict[x][j] == patt[j][k])
						break;
				}
				if (k == len[j])
					break;
			}
			ans += (j == l);
		}
		
		printf("Case #%d: %d\n",i+1,ans);
	}
	
	return 0;
}
