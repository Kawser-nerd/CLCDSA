#include<stdio.h>
#define abs(a) (((a)<0)?-(a):(a))
int main(int argc, char const *argv[]){
	long long n,a,b,c,d;
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
	if((c+d)<=(n-1)*(d-c)){
		if((abs(b-a)/d+(abs(b-a)%d!=0))<=n-1) printf("YES\n");
		else printf("NO\n");
	}else{
		if((abs(b-a)/d+(abs(b-a)%d!=0))>n-1) printf("NO\n");
		else{
			b=b-a+(n-1)*d;
			if(0<=b%(c+d) && b%(c+d)<=(n-1)*(d-c)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
  ^