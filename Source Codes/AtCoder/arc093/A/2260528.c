#include <stdio.h>
#include <math.h>
 
int main(void) {
	int n, A[100001],i,j,sum,tmp;
	A[0] = 0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	
		sum = 0;
		for(i=1;i<=n;i++) sum += abs(A[i]-A[i-1]);
		sum += abs(A[n]);
	
	for(j=1;j<=n;j++){
		tmp = sum;
		tmp -= abs(A[j]-A[j-1]) + abs(A[j+1]-A[j]);
		tmp += abs(A[j+1]-A[j-1]);
		printf("%d\n",tmp);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:28: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
   for(i=1;i<=n;i++) sum += abs(A[i]-A[i-1]);
                            ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A[i]);
   ^