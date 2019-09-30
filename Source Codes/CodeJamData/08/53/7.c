#include <stdio.h>
int n,c,C,i,m,j,k;
int ok[1024],nei[1024];
int maxc[1024][100], cntb[1024];
char str[100][100];
int main() {
	scanf("%d",&C);
	for(i=0;i<1024;i++) {
		ok[i] = (i & (i>>1)) == 0;
		for(j=0;j<20;j++) {
			if(i&(1<<j)) cntb[i]++;
		}
		nei[i] = ((i>>1) | (i<<1)) & 1023;
	}
	for(c=1;c<=C;c++) {
		memset(maxc,0,sizeof(maxc));
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++) {
			scanf("%s",str[i]);
		}
		for(i=m-1;i>=0;i--) {
			int mask = 0;
			for(j=0;j<n;j++) if(str[i][j] == 'x') mask |= 1 << j;
//			printf("mask: %d\n",mask);
			for(k=0;k<(1<<n);k++) if(1||(k&mask)==mask) for(j=0;j<(1<<n);j++) if(ok[j] && !(j&k) && !(j&mask)) {
			//	printf("trying %d\n",j);
				if(maxc[(nei[j]&((1<<n)-1))][i] < cntb[j] + maxc[k][i+1])
					maxc[(nei[j]&((1<<n)-1))][i] = cntb[j] + maxc[k][i+1];
			}
		}
//		for(j=0;j<m;j++) {
//		printf("line %d:",j);
//		for(i=0;i<(1<<n);i++) {
//			printf(" %5d:%2d",i,maxc[i][j]);
//		}
//		puts("");
//		}
//			int mask = 0;
//			for(j=0;j<n;j++) if(str[0][j] == 'x') mask |= 1 << j;
		int maxtotal = 0;
		for(i=0;i<(1<<n);i++) {
			if(maxc[i][0] > maxtotal) maxtotal = maxc[i][0];
		}
		fprintf(stderr,"\r%d/%d\n",c,C); fflush(stderr);
		printf("Case #%d: %d\n",c,maxtotal);
	}
//	fprintf(stderr,"\n");
	return 0;
}
