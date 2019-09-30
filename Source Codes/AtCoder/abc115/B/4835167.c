#include <stdio.h>

int main(void){
	int N,i;
	int max=0;
	int ans=0;
	int temp;
	int p[10000]={};
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&temp);
		ans += temp;
		if(max < temp){
			max = temp;
		}
	}
	printf("%d",ans-(max)/2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&temp);
   ^