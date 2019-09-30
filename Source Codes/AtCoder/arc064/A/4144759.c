#include<stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

int main(){
	int n,i;
	long a[100000],x;
	long long ans=0;
	scanf("%d%ld",&n,&x);
	for(i=0;i<n;i++)scanf("%ld",&a[i]);
	for(i=0;i<n-1;i++){
		if(a[i]+a[i+1]>x){
			if(x-a[i]>=0){
				ans+=(a[i+1]-(x-a[i]));
				a[i+1]=x-a[i];
			}
			else {
				ans+=(a[i+1]+a[i]-x);
				a[i+1]=0;
				a[i]=x;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%ld",&n,&x);
  ^
./Main.c:10:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%ld",&a[i]);
                  ^