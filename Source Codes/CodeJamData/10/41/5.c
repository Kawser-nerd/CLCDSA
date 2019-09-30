#include<stdio.h>
#include<string.h>

int a[64][64];
int b[256][256];
int n,m;

int judge(int m) {
	int j,k;
	for(j=0;j<m;j++) for(k=0;k<m;k++) if (b[j][k]!=-1) {
		if (b[k][j]==-1) b[k][j]=b[j][k]; else if (b[j][k]!=b[k][j]) return 0;
		if (b[m-1-j][m-1-k]==-1) b[m-1-j][m-1-k]=b[j][k]; else if (b[m-1-j][m-1-k]!=b[j][k]) return 0;
		if (b[m-1-k][m-1-j]==-1) b[m-1-k][m-1-j]=b[j][k]; else if (b[m-1-k][m-1-j]!=b[j][k]) return 0;
	}
	return 1;
}

int cal(int m) {
	int i,j,k,l;
	for(i=0;i+n<=m;i++) for(j=0;j+n<=m;j++) {
		memset(b,0xff,sizeof(b));
		for(k=0;k<n;k++) for(l=0;l<n;l++) b[i+k][j+l]=a[k][l];
		if (judge(m)) return 1;
	}
	return 0;
}

int main() {
	int N,cs=0,i,j,k;
	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<n+n-1;i++) {
			for(j=0;j<n && j<=i;j++) if (i-j<n) scanf("%d",&a[j][i-j]);
		}
		for(m=n;;m++) {
			if (cal(m)) break;
		}
		printf("Case #%d: %d\n",++cs,m*m-n*n);
	}
	return 0;
}
