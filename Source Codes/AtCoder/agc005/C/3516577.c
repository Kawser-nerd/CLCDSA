#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

int n,a[110];
int main(){
	scanf("%d",&n);
	int M=0;
	rep(i,0,n){
		int t;
		scanf("%d",&t);
		a[t]++;
		M=max(M,t);
	}
	
	int ngflag=0;
	if(M%2==0){
		rep(i,0,M/2)ngflag|=a[i]!=0;
		rep(i,M/2+1,M+1)ngflag|=a[i]<=1;
		if(a[M/2]!=1)ngflag=1;
	}else{
		if(n!=2&&M==1)ngflag=1;
		rep(i,0,M/2+1)ngflag|=a[i]!=0;
		rep(i,M/2+2,M+1)ngflag|=a[i]<=1;
		if(a[M/2+1]!=2)ngflag=1;
	}
	puts(ngflag?"Impossible":"Possible");
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^