#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 220
ll M,F;int n,p[N];ll P[N],S[N];
bool cmp(int x,int y){return P[x]<P[y];}
ll ff(ll x)
{
	ll TF=M-F*x,Sw=0;int la=0;
	for(int _w=0;_w<n;_w++)
	{
		int i=p[_w];
		if(S[i]<la)continue;
		ll w=min(TF/P[i],(S[i]-la+1)*x);
		if(w==TF/P[i])return Sw+w;
		Sw+=w,la=S[i]+1,TF-=w*P[i];
	}
	return Sw;
}
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%lld%lld%d",&M,&F,&n);
		for(int i=0;i<n;i++)scanf("%lld%lld",P+i,S+i),p[i]=i;
		sort(p,p+n,cmp);
		ll le=1,ri=M/F;
		while(ri-le>=10)
		{
			ll l2=(le*2+ri)/3,r2=(le+ri*2)/3;
			ll f1=ff(l2),f2=ff(r2);
			if(f1>f2)ri=r2;else le=l2;
		}
		ll S=0;
		for(ll t=le;t<=ri;t++)S=max(S,ff(t));
		printf("Case #%d: %lld\n",__,S);
	}
	return 0;
}
