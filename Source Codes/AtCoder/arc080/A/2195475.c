#include<stdio.h>
#include<stdlib.h>
#define ll long long

#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll a[3];
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		ll t;
		scanf("%lld",&t);
		if(t%2)a[0]++;
		else if(t%4)a[1]++;
		else a[2]++;
	}
	if(a[1])a[0]++;
	puts(a[2]+1<a[0]?"No":"Yes");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^