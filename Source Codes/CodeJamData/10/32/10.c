#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

int main(int argc, char *argv[])
{
	int i=0,j=0,k=0;
	long long L,P;
	int C,cas=1,res,T,cnt;

	scanf("%d",&T);
	while (T--){
		scanf("%lld %lld %d",&L,&P,&C);
		cnt = 0;
		while (L*C<P){
			L*=C;
			cnt++;
		}

		res = 0;
		while (cnt){
			cnt /= 2;
			res++;
		}
		printf("Case #%d: %d\n",cas++,res);
	}
	return 0;
}
