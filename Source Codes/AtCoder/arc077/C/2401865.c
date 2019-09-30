#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

ll coef[100010];
ll cons[100010];

int a[100010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
 
	rep(i,1,n+1)scanf("%d",a+i);
		
	rep(i,1,n){
		//a[i],a[i+1]???
		int l=a[i],r=a[i+1];
		if(r<l)r+=m;
		if(r-l<=1)continue;
		if(r>m){
			ll con=-a[i]-1;
			coef[l+2]++;
			coef[m+1]--;
			cons[l+2]+=con;
			cons[m+1]-=con;
			con+=m;
			coef[1]++;
			coef[r-m+1]--;
			cons[1]+=con;
			cons[r-m+1]-=con;			
		}else{
			ll con=-a[i]-1;
			coef[l+2]++;
			coef[r+1]--;
			cons[l+2]+=con;
			cons[r+1]-=con;
		}
	}
	rep(i,1,m+1){
		coef[i]+=coef[i-1];
		cons[i]+=cons[i-1];
	}

	ll otoku=0;
	rep(i,1,m+1){
		ll t=coef[i]*i+cons[i];
		otoku=max(otoku,t);
	}
	
	ll sum=0;
	rep(i,1,n)sum+=(a[i+1]-a[i]+m)%m;
	
	printf("%lld\n",sum-otoku);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:15:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,1,n+1)scanf("%d",a+i);
              ^