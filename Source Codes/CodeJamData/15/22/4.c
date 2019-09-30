#include<stdio.h>

int cnt(int mask) {
	return mask?(mask&1)+cnt(mask>>1):0;
}

int n,m;

int valid(int x,int y) {
	return x>=0 && y>=0;
}

int main() {
	int N,cs=0,i,j,K,ret,T,t;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d",&n,&m,&K);
		ret=1000000000;
		T=n*m;
		for(i=0;i<(1<<T);i++) if (cnt(i)==K) {
			for(t=j=0;j<T;j++) if (i&(1<<j)) {
				if (j%m>0 && (i&(1<<(j-1)))) t++;
				if (j>=m && (i&(1<<(j-m)))) t++;
			}
			if (t< ret) ret=t;
		}
		printf("Case #%d: %d\n",++cs,ret);
	}
	return 0;
}
