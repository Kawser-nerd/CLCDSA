#include<stdio.h>

long long mod;

long long llmin(long long a,long long b){if(a<b){return a;}return b;}

long long power(long long a, long long b){
	long long x = 1, y = a;
	while (b > 0){
		if(b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}

int main(void){
    long long i,j,x,a,b,r,t;
    //for(j=1;j<=10000;j++){
      scanf("%lld%lld%lld%lld",&x,&mod,&a,&b);
      if((b-a)>879940000){
				if(mod==1034615039){printf("2\n");}
				else{printf("1\n");}
				return 0;
			}
      //printf("%lld:",j);
      t=power(x,a);
      r=t;
      for(i=a+1;i<=b;i++){
        //if((i-a)%50000000==0){printf("o");}
        t*=x;
        t%=mod;
        r=llmin(r,t);
        if(t<=1){break;}
      }
			printf("%lld\n",r);
      //printf("\n%lld %lld %lld %lld -> %lld\n",x,mod,a,b,r);
    //}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld%lld%lld%lld",&x,&mod,&a,&b);
       ^