#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,c,C,i,j;
int obs[104][104];
int count[104][104];
int main() {
	scanf("%d",&C);
	for(c=1;c<=C;c++) {
		int w,r;
		scanf("%d%d%d",&n,&w,&r);
		memset(obs,0,sizeof(obs));
		memset(count,0,sizeof(count));
		for(i=0;i<r;i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			obs[x-1][y-1] = 1;
		}
		count[0][0] = 1;
		for(i=1;i<n;i++) {
			for(j=1;j<w;j++) {
				if(!obs[i][j]) {
					int cnt = 0;
					if(i>1) cnt += count[i-2][j-1];
					if(j>1) cnt += count[i-1][j-2];
					count[i][j] = cnt % 10007;
				}
			}
		}
		fprintf(stderr,"\r%d/%d",c,C); fflush(stderr);
		printf("Case #%d: %d\n",c,count[n-1][w-1]);
	}
	fprintf(stderr,"\n");
	return 0;
}
