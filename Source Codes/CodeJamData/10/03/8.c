#include<stdio.h>
#include<string.h>

int a[1024],b[1024];
long long s[1024];
int n,m,p;

int main() {
	int N,cs=0,i,j,k;
	long long ret,t;

	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d",&m,&p,&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		ret=0;
		memset(b,0xff,sizeof(b));
		memset(s,0,sizeof(s));
		for(i=k=0;k<m;k++) {
			if (b[i]>=0) {
				ret+=(m-k)/(k-b[i])*(ret-s[i]);
				k+=(m-k)/(k-b[i])*(k-b[i]);
				memset(b,0xff,sizeof(b));
				if (k==m) break;
			}
			for(t=j=0;j<n;j++) {
				if (t+a[(i+j)%n]>p) break;
				t+=a[(i+j)%n];
			}
			b[i]=k;
			s[i]=ret;
			ret+=t;
			i=(i+j)%n;
		}
		printf("Case #%d: %lld\n",++cs,ret);
	}
	return 0;
}
