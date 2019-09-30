#include<stdio.h>

int b[1000011];
int p[100000];
int pcnt;

void init() {
	for(int i=2;i<=1000010;i++) {
		if (!b[i]) p[pcnt++]=i;
		for(int j=0;p[j]*i<=1000010;j++) {
			b[p[j]*i]=1;
			if (i%p[j]==0) break;
		}
	}
}

int main() {
	int N,cs=0;
	init();
	for(scanf("%d",&N);N--;) {
		long long n;
		int ret=0;
		scanf("%lld",&n);
		if (n==1) {
			printf("Case #%d: 0\n",++cs);
			continue;
		}
		for(int i=0;i<pcnt && (long long)p[i]*p[i]<=n;i++) {
			for(long long m=n;m>=p[i];m/=p[i]) ret++;
			ret--;
		}
		printf("Case #%d: %d\n",++cs,++ret);
	}
	return 0;
}
