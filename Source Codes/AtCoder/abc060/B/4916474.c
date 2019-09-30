#include <stdio.h>

int main(void)
{
	int a,b,c;
	int count=0;
	int sum=0;
	
	scanf("%d%d%d",&a,&b,&c);
	
	for(int i=0;i<101;i++){
		
		sum=sum+a;
		
		if(sum%b==c){
			count++;
		}
	}
	
	if(count!=0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^