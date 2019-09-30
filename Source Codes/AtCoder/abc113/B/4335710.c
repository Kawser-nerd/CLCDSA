#include<stdio.h>
#include<math.h>

int main(void)
{
	int N,i,ans=0;
	double T,A,H[1000],diff,minDiff;

	scanf("%d",&N);
	scanf("%lf %lf",&T,&A);

	minDiff=100000;

	for(i= 1;i <= N;i++) {
		scanf ("%lf",&H[i]);
		diff= fabs(A-(T- H[i]*0.006));

		if(diff < minDiff){
			minDiff= diff;
			ans= i;
		}
	}

	printf("%d",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf",&T,&A);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%lf",&H[i]);
   ^