#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=j;i>=k;i--)
#define LL long long
using namespace std;
inline int read() {
	int x = 0,f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f = -1; ch = getchar(); }
	while(ch>='0'&&ch<='9') { x = x *10+ch-48 ; ch = getchar(); }
	return x * f ;
}

const int N = 1e5+11;
int n,m;
int a[N];
LL p[N*2];
LL all,ans;

int main() {
	n=read(); m=read();
	all = 0;
	For(i, 0, n-1) a[i]=read(); 
	For(i, 1, n-1) {
		int l = a[i-1], r = a[i];
		if(l>r) r+=m;
		all+= r-l;
		if( r-l>1 ) {
			p[l+2] += 1;
			p[r+1] -= r-(l+2)+1 +1;
			p[r+2] += r-(l+2)+1;
		}
	}
	For(i, 1, 2*m) p[i]+=p[i-1];
	For(i, 1, 2*m) p[i]+=p[i-1];
	For(i, 1, m) ans=max(ans,p[i]+p[i+m]);
	printf("%lld\n",all-ans);
	return 0;
}