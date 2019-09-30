#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)

ll c[100010];
ll ans,c2;
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		int t;
		scanf("%d",&t);
		c[t]++;
	}
	rep(i,0,100010){
		while(c[i]>2){
			ans++;
			c[i]-=2;
		}
		if(c[i]==2)c2++;
	}
	ans+=(c2+1)/2;
	printf("%d\n",n-2*ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d\n",n-2*ans);
         ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^