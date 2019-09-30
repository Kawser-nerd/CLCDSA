#include<stdio.h>

#define mod 1000000007

long long calc(long long a,long long b){
	if(b==0)return 1;
	if(b%2==0){
		long long i=calc(a,b/2);
		return (i*i)%mod;
	}
	return (a*calc(a,b-1))%mod;
}

long long ka(int a){
	if(a==1)return 1;
	return (a*ka(a-1))%mod;
}

long long ncm(int a,int b){
	return ((ka(a)*calc(ka(b),mod-2))%mod*calc(ka(a-b),mod-2))%mod;
}

int main(){
	int h,w;
	scanf("%d%d",&w,&h);w--;h--;
	printf("%lld\n",ncm(w+h,h));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&w,&h);w--;h--;
  ^