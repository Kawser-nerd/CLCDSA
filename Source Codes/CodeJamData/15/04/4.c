#include<stdio.h>

int cal(int x,int n,int m) {
	int t;
	if (n>m) t=n,n=m,m=t;
	if (n*m%x!=0) return 0;
	if (x<3) return 1;
	if (x==3) return n>1;
	if (x==4) return n>2;
	if (x==5) {
		if (n<3) return 0;
		if (n==3 && m==5) return 0;
		return 1;
	}
	if (x==6) return n>3;
	return 0;
}

int main() {
	int cs=0,N,n,m,x;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d",&x,&n,&m);
		if (cal(x,n,m)) printf("Case #%d: GABRIEL\n",++cs);
		else printf("Case #%d: RICHARD\n",++cs);
	}
	return 0;
}