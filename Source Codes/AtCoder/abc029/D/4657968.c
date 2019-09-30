#include <stdio.h>
#include <stdlib.h>
int main(void){
	int N,ans=0,i;
	scanf("%d",&N);
	int keta = 0;
	i = N;
	while(i>=1){
		keta++;
		i /= 10;
	}
	N++;
	int set = 10,kosuu = 1;
	for(i=1;i<=keta;i++){
		int n = N;
		ans += (n/set)*kosuu;
		int r = n%set;
		if(r!=0){
			if(r>kosuu*2)r=kosuu*2;
			if(r>kosuu)ans += r-kosuu;
		}
		set *= 10;
		kosuu *= 10;
	}
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^