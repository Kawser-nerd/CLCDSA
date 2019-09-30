#include <stdio.h>

int main(void)
{
	int n,a,i,ans=0;
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		scanf("%d",&a);
		while (a%2==0){
			ans++;
			a = a/2;
		}

	}
	printf("%d\n",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^