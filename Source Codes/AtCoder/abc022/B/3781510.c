#include<stdio.h>

int main(){
		int n,a[100000],b[100001]={0},ans=0,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		for(i=0;i<n;i++){
				b[a[i]]++;
		}
		for(i=0;i<=100000;i++){
				if(b[i]>1)ans+=b[i]-1;
		}
		printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&a[i]);
                   ^