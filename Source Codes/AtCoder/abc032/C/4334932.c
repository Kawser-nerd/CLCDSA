#include<stdio.h>

int main(){
	int n,i,ans=0,c=0,f=0;
	long long k,l=1,a[100000],min=2000000000000;
	scanf("%d%lld",&n,&k);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<min)min=a[i];
		if(a[i]==0)f=1;
	}
	if(min>k){
		puts("0");
		return 0;
	}
	if(f==1){
		printf("%d\n",n);
		return 0;
	}
	for(i=0;i<n;i++){
		l=l*a[i];
		while(l>k&&l>1){
			l=l/a[c];
			c++;
		}
		if(ans<i-c+1)ans=i-c+1;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld",&n,&k);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^