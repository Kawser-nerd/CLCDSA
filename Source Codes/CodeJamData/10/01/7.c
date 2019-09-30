#include<stdio.h>

int main() {
	int N,n,k,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&n,&k);
		if (((k+1)>>n<<n)==k+1) printf("Case #%d: ON\n",++cs); else printf("Case #%d: OFF\n",++cs);
	}
	return 0;
}
