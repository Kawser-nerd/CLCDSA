#include <stdio.h>
#include <string.h>

int zip[11];
char g[11][11];
int n;

int path[11];
int best[11];
int cur[11];

void btr(int num,int sp,int mask,int stack[8]) {
	int i,we=stack[sp-1];
	int stakk[8];
	for(i=0;i<n;i++) stakk[i]=stack[i];
	for(i=0;i<num;i++) {
		if(cur[i]>best[i]) return;
		if(cur[i]<best[i]) break;
	}
	if(num==n) {
		for(i=0;i<n;i++) best[i]=cur[i];
		return;
	}
	/* go to next */
	for(i=0;i<n;i++) if(!(mask&(1<<i)) && g[we][i]) {
		cur[num]=zip[i];
		path[num]=i;
		stakk[sp]=i;
		btr(num+1,sp+1,mask+(1<<i),stakk);
	}
	/* use return flight */
	if(sp>1) btr(num,sp-1,mask,stakk);
}

void solve() {
	int i,m,a,b,z,stack[8];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&zip[i]);
	memset(g,0,sizeof(g));
	for(i=0;i<m;i++) {
		scanf("%d %d",&a,&b);
		g[--a][--b]=1;
		g[b][a]=1;
	}
	best[0]=999999;
	for(z=i=0;i<n;i++) if(zip[z]>zip[i]) z=i;
	path[0]=z;
	stack[0]=z;
	cur[0]=zip[z];
	btr(1,1,1<<z,stack);
	for(i=0;i<n;i++) printf("%d",best[i]);
	printf("\n");
}

int main() {
	int t,no=1;
	scanf("%d",&t);
	while(t--) printf("Case #%d: ",no++),solve();
	return 0;
}
