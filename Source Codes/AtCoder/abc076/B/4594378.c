#include <stdio.h>

int main(void)
{
	int n,k,ans_A,ans_B;
	int ans=1;
	
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n;i++){
		
		ans_A=ans*2;
		ans_B=ans+k;
		
		if(ans_A>=ans_B){
			ans=ans_B;
		}else{
			ans=ans_A;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^