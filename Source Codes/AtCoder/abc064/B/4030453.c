#include<stdio.h>

int main(){
		int n,a[100],i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		for(i=0;i<n;i++){
				for(j=0;j<n;j++){
						if(a[i]<a[j]){
								int tmp=a[i];
								a[i]=a[j];
								a[j]=tmp;
						}
				}
		}
		printf("%d",a[n-1]-a[0]);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&a[i]);
                   ^