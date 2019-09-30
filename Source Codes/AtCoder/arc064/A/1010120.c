#include<stdio.h>

int main(){
	long n,a[100000],x,i;
	long long eat;
	scanf("%ld %ld",&n,&x);
	eat=0LL;
	for(i=0;i<n;i++){
		scanf("%ld",&a[i]);
		if(i>0){
			if(i==1){
				if(a[i]+a[i-1]>x){
					eat+=a[i]+a[i-1]-x;
					a[i]-=a[i]+a[i-1]-x;
					if(a[i]<0){
						a[i-1]+=a[i];
						a[i]=0;
					}
				}
			}else{
				if(a[i]+a[i-1]>x){
					eat+=a[i]+a[i-1]-x;
					a[i]-=(a[i]+a[i-1]-x);
				}
			}
		}
	}
	printf("%lld\n",eat);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&n,&x);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&a[i]);
   ^