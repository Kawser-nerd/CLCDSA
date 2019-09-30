#include<stdio.h>

int main(){
		long long a,b,c,ans=0;
		scanf("%lld%lld%lld",&a,&b,&c);
		while(a%2==0&&b%2==0&&c%2==0){
				if(a==b&&b==c){
						puts("-1");
						return 0;
				}
				ans++;
				long long tmp=a;
				long long tmp1=b;
				long long tmp2=c;
				a=tmp1/2+tmp2/2;
				b=tmp/2+tmp2/2;
				c=tmp/2+tmp1/2;
		}
		printf("%lld\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&a,&b,&c);
   ^