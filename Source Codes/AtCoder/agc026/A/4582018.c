#include <stdio.h>
#include <stdlib.h>
int main(void){
	int n,ans=0,i,a,b;
	scanf("%d",&n);
	scanf("%d",&b);
	for(i=1;i<n;i++){
		scanf("%d",&a);
		if(b==a){
			ans++;
			b = 0;
		}else	b = a;
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&b);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^