#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

#define PI 3.1415926535

double x[110],y[110];
double ans[110];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lf%lf",x+i,y+i);
	rep(i,0,n){
		double m[20],M[20];
		int cnt[20];
		rep(t,0,20)m[t]=INF,M[t]=-INF,cnt[t]=0;
		rep(j,0,n)if(i!=j){
			double s=atan2(y[j]-y[i],x[j]-x[i]);
			s=(s+PI)/(2*PI);
			if(s>=1)s=0;
			if(s<0)s=0;
			int t=s*20;
			cnt[t]++;
			m[t]=min(m[t],s);
			M[t]=max(M[t],s);
		}
		rep(k,0,20)if(cnt[k]){
			int t=1;
			while(!cnt[(k+t)%20])t++;
			if(t<10)continue;
			double s=m[(k+t)%20]-M[k];
			if(s<0)s++;
			if(s==0)s=1;
			if(s<0.5)continue;
			ans[i]=s-0.5;
			break;
		}
	}
	rep(i,0,n)printf("%.9f\n",ans[i]);
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:17:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lf%lf",x+i,y+i);
            ^