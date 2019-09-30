#include <stdio.h>
#include <string.h>

int m[105][105], r, c;
char ans[105][105], visited[105][105], now;

char dfs(int i, int j) {
	int ii = -1, jj = -1, h = m[i][j];
	
	if (visited[i][j])
		return ans[i][j];
	
	visited[i][j] = 1;
	
	if (i > 0 && m[i-1][j] < h)
		ii = -1, jj = 0, h = m[i-1][j];
	if (j > 0 && m[i][j-1] < h)
		ii = 0, jj = -1, h = m[i][j-1];
	if (j < c-1 && m[i][j+1] < h)
		ii = 0, jj = 1, h = m[i][j+1];
	if (i < r-1 && m[i+1][j] < h)
		ii = 1, jj = 0, h = m[i+1][j];
	
	return ans[i][j] = (ii == -1 && jj == -1) ? now++ : dfs(i+ii,j+jj);
}

int main() {
	int t, caso = 1, i, j;
	
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&r,&c);
		for (i=0; i < r; i++) {
			for (j=0; j < c; j++) {
				scanf("%d",&m[i][j]);
			}
		}
		
		now = 'a';
		memset(visited,0,sizeof(visited));
		for (i=0; i < r; i++) {
			for (j=0; j < c; j++) {
				if (!visited[i][j]) {
					dfs(i,j);
				}
			}
		}
		
		printf("Case #%d:\n",caso++);
		for (i=0; i < r; i++) {
			printf("%c",ans[i][0]);
			for (j=1; j < c; j++) {
				printf(" %c",ans[i][j]);
			}
			puts("");
		}
	}
	
	return 0;
}
