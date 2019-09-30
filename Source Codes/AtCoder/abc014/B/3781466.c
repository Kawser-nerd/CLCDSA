#include<stdio.h>

int main(){
		int n,a[20],i;long x;
		scanf("%d%ld",&n,&x);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		int ans=0;
		for(i=0;i<n;i++){
				if(x&1<<i){
						ans+=a[i];
				}
		}
		printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%ld",&n,&x);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&a[i]);
                   ^