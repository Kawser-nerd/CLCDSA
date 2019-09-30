#include <stdio.h>
#define N 60
int main() {
	int t, T, n, k, ii;
	int i, j, ans[2];
	char map[N][N];
	char map2[N][N];
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		ans[0]=ans[1]=0;
		scanf("%d %d", &n, &k);
		for(i=0;i<n;i++) {
			scanf("%s", map[i]);
		}
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				map2[j][n-i-1] = map[i][j];
			}
			map2[i][n]='\0';
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				map[i][j] = '.';
		for(i=0;i<n;i++) {
			int count=0;
			for(j=n-1;j>=0;j--) {
				if(map2[j][i] != '.') map[n-1-count++][i]=map2[j][i];
			}
		}
		//for(i=0;i<n;i++)
		//	printf("%s\n", map[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) {
				if(map[i][j] == '.') continue;
				if(i+k<=n) {
					for(ii=0;ii<k;ii++) {
						if(map[i][j] != map[i+ii][j]) break;
					}
					if(ii == k) {
						ans[map[i][j] == 'B' ? 0:1] = 1;	
					}
				}
				if(j+k<=n) {
					for(ii=0;ii<k;ii++)
						if(map[i][j] != map[i][j+ii]) break;
					if(ii == k) {
						ans[map[i][j] == 'B' ? 0:1] = 1;
					}
				}
				if(i+k<=n && j+k<=n) {
					for(ii=0;ii<k;ii++) {
						if(map[i][j] != map[i+ii][j+ii]) break;
					}
					if(ii==k) ans[map[i][j] == 'B'?0:1]=1;
				}
				if(i+k<=n && j-k+1>=0) {
					for(ii=0;ii<k;ii++) {
						if(map[i][j] != map[i+ii][j-ii]) break;
					}
					if(ii==k) ans[map[i][j] == 'B'?0:1]=1;
				}
			}
		printf("Case #%d: ", t+1);
		if(ans[0] && ans[1]) printf("Both\n");
		else if(ans[0]) printf("Blue\n");
		else if(ans[1]) printf("Red\n");
		else printf("Neither\n");
	}
	return 0;
}
