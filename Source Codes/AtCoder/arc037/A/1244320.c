#include <stdio.h>

int main(void)
{
	int i,n,count=0;
	int m[30];
	
	scanf("%d",&n);
	for(i=0;i<=n-1;i++){
		scanf("%d",&m[i]);
	}
	
	for(i=0;i<=n-1;i++){
		if(m[i]-80<0){
			count+=80-m[i];
		}
	}
	
	printf("%d\n",count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m[i]);
   ^