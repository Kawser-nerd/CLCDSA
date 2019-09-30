#include<stdio.h>

long long sx[512][512],sy[512][512];
int a[512][512];
long long b[512][512];
int n,m,D;
char s[512][512];

int main() {
	int N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d",&n,&m,&D);
		for(int i=0;i<n;i++) {
			scanf("%s",s[i]);
			for(int j=0;j<m;j++) {
				a[i][j]=s[i][j]-'0'+D;
				b[i+1][j+1]=b[i+1][j]-b[i][j]+b[i][j+1]+a[i][j];
				sx[i+1][j+1]=sx[i+1][j]-sx[i][j]+sx[i][j+1]+(long long)a[i][j]*i*2;
				sy[i+1][j+1]=sy[i+1][j]-sy[i][j]+sy[i][j+1]+(long long)a[i][j]*j*2;
			}
		}
		int ret=-1;
		for(int len=3;len<=n && len<=m;len++) {
			bool flag=false;
			for(int i=0;i<=n-len && !flag;i++) for(int j=0;j<=m-len && !flag;j++) {
				long long mass=b[i+len][j+len]-b[i+len][j]-b[i][j+len]+b[i][j];
				long long jux=sx[i+len][j+len]-sx[i+len][j]-sx[i][j+len]+sx[i][j];
				long long juy=sy[i+len][j+len]-sy[i+len][j]-sy[i][j+len]+sy[i][j];
				int cx=i+i+len-1,cy=j+j+len-1;
				mass-=a[i][j]+a[i][j+len-1]+a[i+len-1][j]+a[i+len-1][j+len-1];
				jux-=(long long)(a[i][j]+a[i][j+len-1])*i*2+
					(long long)(a[i+len-1][j]+a[i+len-1][j+len-1])*(i+len-1)*2;
				juy-=(long long)(a[i][j]+a[i+len-1][j])*j*2+
					(long long)(a[i][j+len-1]+a[i+len-1][j+len-1])*(j+len-1)*2;
				if (jux==mass*cx && juy==mass*cy) flag=true;
			}
			if (flag) ret=len;
		}
		if (ret>=0) printf("Case #%d: %d\n",++cs,ret); else printf("Case #%d: IMPOSSIBLE\n",++cs);
	}
	return 0;
}
