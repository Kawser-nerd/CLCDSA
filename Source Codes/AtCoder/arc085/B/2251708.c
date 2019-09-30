#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

int main(){
	int n,x;
	scanf("%d%*d%d",&n,&x);
	int l2,l1;
	rep(i,0,n){
		l2=l1;
		scanf("%d",&l1);
	}
	
	if(n==1)printf("%d\n",abs(l1-x));
	else printf("%d\n",max(abs(l1-x),abs(l2-l1)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%*d%d",&n,&x);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&l1);
   ^