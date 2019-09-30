#include<stdio.h>
#define MOD 1000000009+7

int main(){
	long long n,h,a,b,c,d,e;
	long long i,ans=-1,req;
	scanf("%lld %lld",&n,&h);
	scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e);
	b+=e;
	d+=e;
	req=e*n-h+1;
	for(i=0;i<=(req/b)+1;i++){
		long long r=req-b*i;
		long long tmp;
		if(r<=0){
			tmp=a*i;
		}else{
			tmp=c*((r+d-1)/d)+a*i;
		}
		if(ans==-1 || tmp<ans)ans=tmp;
	}
	if(ans==-1)ans=0;
	printf("%lld\n",ans);	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&h);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e);
  ^