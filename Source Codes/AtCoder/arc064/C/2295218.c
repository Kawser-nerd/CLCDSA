#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))

//???????????????????????????
//O(V^2)
double cost[1010][1010];
double daikusutorap[1010];
void daikusutora(ll n,ll s){
	ll*f=(ll*)malloc(n*sizeof(ll));
	rep(i,0,n){
		daikusutorap[i]=i==s?0:INF;
		f[i]=0;
	}
	rep(nnnnnn,1,n){
		ll m=INF,mv=-1;
		rep(i,0,n){
			if(!f[i]&&m>daikusutorap[i]){
				m=daikusutorap[i];
				mv=i;
			}
		}
		if(mv==-1)break;
		f[mv]=1;
		rep(i,0,n)if(daikusutorap[i]>daikusutorap[mv]+cost[mv][i]){
			daikusutorap[i]=daikusutorap[mv]+cost[mv][i];
		}
	}
	free(f);
}


double x[1010],y[1010],r[1010];
int main(){
	double sx,sy,gx,gy;
	scanf("%lf%lf%lf%lf",&sx,&sy,&gx,&gy);
	int n;
	scanf("%d",&n);
	n+=2;

	x[  0]=sx;y[  0]=sy;r[  0]=0;
	x[n-1]=gx;y[n-1]=gy;r[n-1]=0;
	
	rep(i,1,n-1)scanf("%lf%lf%lf",x+i,y+i,r+i);
	
	rep(i,0,n)rep(j,0,n){
		double d=hypot(x[i]-x[j],y[i]-y[j]);
		cost[i][j]=max(d-r[i]-r[j],0);
	}
	daikusutora(n,0);
	printf("%.15f\n",daikusutorap[n-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:12: warning: implicit declaration of function ‘hypot’ [-Wimplicit-function-declaration]
   double d=hypot(x[i]-x[j],y[i]-y[j]);
            ^
./Main.c:50:12: warning: incompatible implicit declaration of built-in function ‘hypot’
./Main.c:50:12: note: include ‘<math.h>’ or provide a declaration of ‘hypot’
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf%lf%lf",&sx,&sy,&gx,&gy);
  ^
./Main.c:41:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:47:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,1,n-1)scanf("%lf%lf%lf",x+i,y+i,r+i);
              ^