#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))

ll a[99],x[99],y[99];
ll ans;
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",a+i);
	
	ll M=-INF,m=INF,Mi,mi;
	rep(i,0,n){
		if(a[i]>M){
			M=a[i];
			Mi=i;
		}
		if(a[i]<m){
			m=a[i];
			mi=i;
		}
	}
	if(M>0&&m<0){
		if(M>=-m)rep(i,0,n){x[ans]=Mi;y[ans]=i;ans++;m+=M;}//??0?????
		else rep(i,0,n){x[ans]=mi;y[ans]=i;ans++;M+=m;}//??0?????
	}
	
	//??????
	if(m>=0)rep(i,1,n){x[ans]=i-1;y[ans]=i;ans++;}//??0?????
	else for(int i=n-1;i>=1;i--){x[ans]=i;y[ans]=i-1;ans++;}//??0?????
	
	printf("%lld\n",ans);
	rep(i,0,ans)printf("%lld %lld\n",x[i]+1,y[i]+1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^