#include<stdio.h>

int f[100000];
long mod=1000000007;

int main(){
	long n,i,a,ans,c;
	scanf("%ld",&n);
	for(i=0;i<n;i++){
		scanf("%ld",&a);
		f[a]++;
	}
	c=0;
	for(i=n-1;i>=0;i-=2){
		if(i>1){
			if(f[i]!=2) break;
			c++;
		}else if(i==1){
			if(f[i]!=2) break;
			c++;
		}else if(f[i]!=1){
			break;
		}
	}
	if(i>=0){
		printf("0\n");
	}else{
		ans=1;
		for(i=0;i<c;i++){
			ans*=2;
			ans%=mod;
		}
		printf("%ld\n",ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&a);
   ^