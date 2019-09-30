#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// ????????????

#define LL long long

int check(LL R,LL B,LL x,LL y,LL K)
{
	if (R<K || B<K)return 0;
	return ((R-K)/(x-1) + (B-K)/(y-1))>=K;
}

int main(void)
{
	LL R,B;
	scanf("%lld %lld\n",&R,&B);
	LL x,y;
	scanf("%lld %lld\n",&x,&y);
	LL smax,smin,scurr;
	smin = 0;
	smax = 1000000000000000000LL; // 1E18
	while (1){
		assert(smin < smax);
		scurr = (smin+smax)/2;
		if (check(R,B,x,y,scurr) && !check(R,B,x,y,scurr+1)){
			break;
		}
		if (check(R,B,x,y,scurr)){
			smin = scurr;
			if (smin == smax)smax++;
		}
		else{
			smax = scurr;
			if (smin == smax){
				if (smin<=0)smax++;
				else smin--;
			}
		}
	}
	assert(check(R,B,x,y,scurr) && !check(R,B,x,y,scurr+1));
	printf("%lld\n",scurr);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld\n",&R,&B);
  ^
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld\n",&x,&y);
  ^