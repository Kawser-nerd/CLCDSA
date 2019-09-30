#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
	
	int N;
	long A,B,C,D;
	scanf("%d %ld %ld %ld %ld", &N, &A, &B, &C, &D);
	
	int diff = abs(A-B);
	
	int found=0;
	for (int i=0; i<=N-1; i++){
		long maxD = (N-1-i)*D+i*C*-1;
		long minD = (N-1-i)*C+i*D*-1;
		if ((diff<=maxD) && (diff>=minD)) found=1;	
	}
		if (found==1)
			printf("YES\n");
		else
			printf("NO\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %ld %ld %ld %ld", &N, &A, &B, &C, &D);
  ^