#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

int a[100010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,2*m){
		int t;
		scanf("%d",&t);
		a[t]^=1;
	}
	int ans=1;
	rep(i,1,n+1)ans&=!a[i];
	puts(ans?"YES":"NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^