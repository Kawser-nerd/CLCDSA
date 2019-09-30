#include<stdio.h>
#include<algorithm>
using namespace std;

long long a[1000001];
int cc[1000000];
long long b[1000000];
int n,L,c,s;
long long T;

int main() {
	int N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %lld %d %d\n",&L,&T,&n,&c);
		for(int i=0;i<c;i++) scanf("%d",&cc[i]);
		for(int i=0;i<n;i++) a[i+1]=cc[i%c]*2;
		a[0]=0;
		s=n;
		for(int i=1;i<=n;i++) {
			a[i]+=a[i-1];
			if (a[i]>T && i-1<s) s=i-1;
		}
		for(int i=s;i<n;i++) if (a[i]<T) b[i-s]=(a[i+1]-T)/2; else b[i-s]=(a[i+1]-a[i])/2;
		sort(b,b+n-s);
		for(int i=0;i<L && n-s-1-i>=0;i++) a[n]-=b[n-s-1-i];
		printf("Case #%d: %lld\n",++cs,a[n]);
	}
	return 0;
}
