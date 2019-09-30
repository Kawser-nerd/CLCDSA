#include <stdio.h>
#include <string.h>

char m[2][1005][1005];

int main() {
	int t, caso = 1;
	int r, n, i, j, i1, j1, i2, j2, born, now, other, ans;
	
	scanf("%d",&t);
	while (t--) {
		memset(m,0,sizeof(m));
		n = 0;
		
		scanf("%d",&r);
		
		if (!r) {
			ans = 0;
			goto END;
		}
		
		while (r--) {
			scanf("%d %d %d %d",&i1,&j1,&i2,&j2);
			if (i2 >= n-1) n = i2 + 2;
			if (j2 >= n-1) n = j2 + 2;
			for (i=i1; i <= i2; i++) {
				for (j=j1; j <= j2; j++) {
					m[0][i][j] = 1;
				}
			}
		}
		
		now = 0;
		born = 1;
		for (ans=0; born; ans++,now=1-now,n++) {
			other = 1 - now;
			born = 0;
			
			m[other][0][0] = 0;
			for (i=1; i < n; i++) {
				m[other][i][0] = (m[now][i][0] && m[now][i-1][0]);
				m[other][0][i] = (m[now][0][i] && m[now][0][i-1]);
				born |= m[other][i][0] | m[other][0][i];
			}
			for (i=0; i < n; i++) {
				for (j=0; j < n; j++) {
					if (m[now][i][j]) {
						m[other][i][j] = (m[now][i-1][j] || m[now][i][j-1]);
					}
					else {
						m[other][i][j] = (m[now][i-1][j] && m[now][i][j-1]);
					}
					born |= m[other][i][j];
				}
			}
		}
		
		END:
		printf("Case #%d: %d\n",caso++,ans);
	}
	
	return 0;
}
