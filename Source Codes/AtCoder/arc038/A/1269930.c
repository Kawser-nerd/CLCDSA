#include <stdio.h>

int main(void)
{
	int n,i,j,temp,ans=0;
	int a[1000];
	scanf("%d",&n);
	
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
	
	
	for (i = 0;i < n - 1;i++) {
		for (j = 0;j < n - 1;j++) {
			if (a[j + 1] < a[j]) {
				temp = a[j];a[j] = a[j + 1];a[j + 1] = temp;
			}
		}
	}
	
	if(n%2==0){
		for(i=n-1;i>=1;i-=2){
			ans+=a[i];
		}
	} else{
		for(i=n-1;i>=0;i-=2){
			ans+=a[i];
		}
	}
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^