#include <stdio.h>
#define MIN(i,j) (i <= j ? i : j)

int main(void)
{
	long long r,b,x,y;
	long long set1 = 0,set2 = 0;
	long long ok,ng,mid;

	scanf("%lld %lld",&r,&b);
	scanf("%lld %lld",&x,&y);

	ng = 1e+18;
	ok = 0;
	while(ng > ok + 1){
		mid = (ng + ok) / 2;
		if(r < mid || b < mid){
			ng = mid;
			continue;
		}
		set1 = (r - mid) / (x - 1);
		set2 = (b - mid) / (y - 1);
		if(set1 + set2 >= mid){
			ok = mid;
		}
		else{
			ng = mid;
		}
	}

	printf("%lld\n",ok);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&r,&b);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&x,&y);
  ^