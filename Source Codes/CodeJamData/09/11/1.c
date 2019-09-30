#include<stdio.h>

#define MAXN 1000000

int usd[9][MAXN];
int check(int n, int base) {
	int s, _n=n;
	if(n==1) return 1;
	if(n<MAXN) {
		if(usd[base-2][n]==1) return 1;
		if(usd[base-2][n]==2) return 0;
		usd[base-2][n]=2;
	}
	s=0;
	while(n) {
		s+=(n%base)*(n%base);
		n/=base;
	}
	s = check(s,base);
	if(s==1 && _n<MAXN) usd[base-2][_n] = 1;
	return s;
}

int main() {
	int t,T,l,i,j;
	char c;
	scanf("%d\n",&T);
	for(t=1;t<=T;t++) {
		l = 0;
		while(1) {
			scanf("%d%c",&i,&c);
			l|=1<<i;
			if(c=='\n') break;
		}
		for(i=2;;i++) {
			for(j=10;j>2;j--) {
				if(((l>>j)&1)&&!check(i,j)) break;
			}
			if(j==2) break;
		}
		printf("Case #%d: %d\n",t,i);
	}
	return 0;
}
