#include<stdio.h>
#include<algorithm>
using namespace std;

long long a[10000];
long long g[10000];
int n;
long long l,h;

long long gcd(long long a,long long b) {
	return b?gcd(b,a%b):a;
}

long long p[64],r[64];
int cnt;

long long dfs(long long a,int k) {
	if (k==cnt) {
		if (a>=l && a<=h) return a; else return -1;
	}
	long long ret=dfs(a,k+1),t;
	for(int i=0;i<r[k];i++) {
		t=dfs(a*=p[k],k+1);
		if (ret<0 || t>=0 && t<ret) ret=t;
	}
	return ret;
}

long long cal(long long lcm,long long gcd) {
	long long t=gcd/lcm;
	cnt=0;
	for(int i=2;(long long)i*i<=t && h/i>=lcm;i++) if (t%i==0) {
		for(p[cnt]=i,r[cnt]=0;t%i==0;t/=i,r[cnt]++);
		cnt++;
	}
	if (t>1 && h/t>=lcm) p[cnt]=t,r[cnt]=1,cnt++;
//	printf("%lld %lld\n",lcm,gcd);
//	printf("%d\n",cnt);
//	for(int i=0;i<cnt;i++) printf("%lld %lld  ",p[i],r[i]);puts("");
	return dfs(lcm,0);
}

int main() {
	int N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %lld %lld\n",&n,&l,&h);
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		sort(a,a+n);
		g[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--) g[i]=gcd(g[i+1],a[i]);
		if (g[0]>=l) {
			long long t=cal(1,g[0]);
			printf("Case #%d: %lld\n",++cs,t);
			continue;
		}
		long long lcm=g[0];
		bool flag=false;
		for(int i=0;i<n-1;i++) {
			long long d=gcd(lcm,a[i]);
			lcm/=d;
			if (h/lcm<a[i]) break;
			lcm*=a[i];
			if (g[i+1]>=l && g[i+1]%lcm==0) {
				long long ans=cal(lcm,g[i+1]);
				if (ans>=0) printf("Case #%d: %lld\n",++cs,ans);
				else printf("Case #%d: NO\n",++cs);
				flag=true;
				break;
			}
		}
		if (flag) continue;
		long long d=gcd(lcm,a[n-1]);
		lcm/=d;
		if (h/lcm>=a[n-1]) lcm*=a[n-1],flag=true;
		if (flag && lcm<l) lcm=(l+lcm-1)/lcm*lcm;
		if (!flag) printf("Case #%d: NO\n",++cs);
		else printf("Case #%d: %lld\n",++cs,lcm);
	}
	return 0;
}
