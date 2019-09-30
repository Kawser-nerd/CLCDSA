#include <stdio.h>
int main(void){
	int N;
	int modnum=0;
	int ans = 0;
	scanf("%d",&N);
	for(int i = 1;i<=N;i+=2){
		modnum=0;
		for(int j=1;j<=N;j++){
			if( i%j == 0){
				modnum++;
			}
		}
		if( modnum ==8){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^