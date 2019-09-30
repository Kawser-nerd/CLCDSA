#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

#define LIMIT 1000000000000
char ss[10];
int main(){
	ll s=10;
	while(s<LIMIT){
		printf("? %lld\n",s);
		fflush(0);
		scanf("%s",ss);
		if(*ss=='N')break;
		s*=10;
	}
	if(s==1000000000000){
		//???10??
		s=2;
		while(s<LIMIT){
			printf("? %lld\n",s);
			fflush(0);
			scanf("%s",ss);
			if(*ss=='Y')break;
			s*=10;
		}
		printf("! %lld\n",s/2);
		fflush(0);
	}else{
		ll l=s/10+1,r=s-1;//[l,r]
		while(l!=r){
			ll m=(l+r)/2;
			printf("? %lld0\n",m);
			fflush(0);
			scanf("%s",ss);
			if(*ss=='N')l=m+1;
			else r=m;
		}
		printf("! %lld\n",l);
		fflush(0);
	}
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",ss);
   ^
./Main.c:23:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",ss);
    ^
./Main.c:35:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",ss);
    ^