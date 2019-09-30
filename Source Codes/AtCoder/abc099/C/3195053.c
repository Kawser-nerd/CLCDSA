#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int ans=N;
	
	for(int i=0;i<=N;i++){
		int count=0;
		int tmp=i;
		
		while(tmp>0){
			count+=tmp%6;
			tmp/=6;
		}
		
		tmp=N-i;
		
		while(tmp>0){
			count+=tmp%9;
			tmp/=9;
		}
		
		if(count<ans)ans=count;
	}
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^