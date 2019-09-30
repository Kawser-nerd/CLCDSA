#include<stdio.h>

long long juk(long long a,long long b){
	if(a%b==0)return b;
	return juk(b,a%b);
}

int main(){
	int n,i;
	long long t[100],ans=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%lld",&t[i]);
	for(i=0;i<n;i++){
		ans=t[i]/juk(t[i],ans)*ans;
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%lld",&t[i]);
                  ^