#include <stdio.h>

int main(void)
{
	int n,count;
	scanf("%d",&n);
	
	count=0;
	
	for(int i=0;7*i<=n;i++){
		if((n-7*i)%4==0){
			count++;
		}
	}
	
	if(count==0){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^