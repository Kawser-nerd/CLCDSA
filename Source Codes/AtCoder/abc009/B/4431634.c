#include <stdio.h>
int main(void){
	int i=0,n,a[100],max=0,second=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>=max) max=a[i];
	}
	for(i=0;i<n;i++){
		if(a[i]!=max){
			if(max-second>max-a[i]) second=a[i];
		}
	}
	printf("%d\n",second);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^