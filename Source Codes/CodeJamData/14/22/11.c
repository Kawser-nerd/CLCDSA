#include <stdio.h>

void solve() {
	int a,b,k,i,j,r=0;
	scanf("%d %d %d",&a,&b,&k);
	for(i=0;i<a;i++) for(j=0;j<b;j++) if((i&j)<k) r++;
	printf("%d\n",r);
}

int main() {
	int t,no=1;
	scanf("%d",&t);
	while(t--) printf("Case #%d: ",no++),solve();
	return 0;
}
