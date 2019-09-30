#include <stdio.h>

 int main(void)
 {
 	int n,k;
 	scanf("%d %d",&n,&k);
 	n>=k*2?puts("YES"):puts("NO");
 	return 0;
 } ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^