#include<stdio.h>
#include<string.h>

int a[64][64];
int b[64],p[64];
int n;

int main() {
	int N,cs=0,i,j,ret,k;
	char tmp[64];

	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<n;i++) {
			scanf("%s",tmp);
			p[i]=-1;
			for(j=0;j<n;j++) {
				a[i][j]=tmp[j]-'0';
				if (a[i][j]) p[i]=j;
			}
			b[i]=0;
		}
		for(ret=i=0;i<n;i++) {
			for(j=0;j<n;j++)
				if (!b[j] && p[j]<=i) break;
			b[j]=1;
			for(k=0;k<j;k++) if (!b[k]) ret++;
		}
		printf("Case #%d: %d\n",++cs,ret);
	}
	return 0;
}
