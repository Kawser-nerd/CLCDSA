#include<stdio.h>
#include<string.h>

int a[1024][12];
int b[1024];
int d[1024];
int q[1024];
int n;

int has(int idx) {
	int i,j,k,tail=0;
	memset(d,0,sizeof(d));
	d[idx]=1;
	q[tail++]=idx;
	for(i=0;i<tail;i++) {
		for(j=0;j<b[q[i]];j++) if (d[a[q[i]][j]]) return 1; else d[a[q[i]][j]]=1,q[tail++]=a[q[i]][j];
	}
	return 0;
}

int main() {
	int N,cs=0,i,j;
	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<n;i++) {
			scanf("%d",&b[i]);
			for(j=0;j<b[i];j++) scanf("%d",&a[i][j]),a[i][j]--;
		}
		for(i=0;i<n;i++) if (has(i)) break;
		if (i<n) printf("Case #%d: Yes\n",++cs); else printf("Case #%d: No\n",++cs);
	}
	return 0;
}
