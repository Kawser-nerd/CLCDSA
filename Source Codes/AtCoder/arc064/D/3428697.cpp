#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
using namespace std;
typedef long long LL;
const int N=100500,mo=1e9+7;
int m,n;
int fj[N][2],fj0;
int d[N];
LL ans;
map<int,int>f;
LL ksm(LL q,int w) {
	LL ans=1;
	for(; w; w>>=1,q=q*q%mo)if(w&1)ans=ans*q%mo;
	return ans;
}
int ss1(int q,int w,int e) {
	if(q>w)return f[e];
	int ans=ss1(q+1,w,e);
	fo(i,1,d[q])((ans+=ss1(q+1,w,(e=e*fj[q][0])))>=mo?ans-=mo:0);
	return ans;
}
void ss(int q,int e) {
	if(q>fj0) {
		LL t=(((n/e)%2?ksm(m,(e+1)>>1):ksm(m,e))-ss1(1,q,1)+mo)%mo;
		f[e]=t;
		ans=(ans+t*e)%mo;
		return;
	}
	d[q]=0;
	ss(q+1,e);
	fo(i,1,fj[q][1])d[q]=i,ss(q+1,(e*=fj[q][0]));
}
int main() {
	int q,w;
	scanf("%d%d",&n,&m);
	if(n==1)return printf("%d\n",m),0;
	q=n;
	for(int i=2; i*i<=q; ++i)if(q%i==0) {
			for(fj[++fj0][0]=i; !(q%i); ++fj[fj0][1],q/=i);
		}
	if(q>1)fj[++fj0][0]=q,fj[fj0][1]=1;
	ss(1,1);
	printf("%lld\n",(ans+mo)%mo);
	return 0;
}