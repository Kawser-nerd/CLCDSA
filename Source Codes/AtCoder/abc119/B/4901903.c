#include <stdio.h>
#include <string.h>
int main(void){
	int N;
	int i,j;
	scanf("%d",&N);
	double ans = 0;
	char s[4];
	double temp;
	for(i=0;i<N;i++){
		scanf("%lf",&temp);
		scanf("%s",s);
		if(strcmp(s,"JPY")==0){
			ans +=temp;
		}else{
			ans +=temp * 380000;
		}
	}
	printf("%lf",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&temp);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^