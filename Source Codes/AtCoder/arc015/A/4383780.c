#include<stdio.h>

int main(){
		int n;
		double ans;
		scanf("%d",&n);
		ans=(9*(double)n/(double)5)+32;
		printf("%.6lf\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^