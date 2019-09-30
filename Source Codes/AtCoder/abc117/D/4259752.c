#include <stdio.h>

#define ull unsigned long long

#define RIGHT_N_BIT_OFF(b, n) ((b) & ((ull)(-1) << (n)))
#define REMAIN_RIGHT_N_BIT(b, n) ((b) & (((ull)(1) << (n)) - 1))

int main()
{
	int i, j;
	int n;
	
	ull k;
	ull a;
	ull best = 0;
	ull x;
	ull count_each_bit[42] = {};
	ull sum = 0;
	ull sum_max = 0;
	
	scanf("%d %llu ", &n, &k);
	
	for(i = 0; i < n; ++i){
		scanf("%llu ", &a);
		for(j = 0; j < 42; ++j)
			count_each_bit[j] += (a>>j) & 1;
	}
	
	for(i = 0; i < 42; ++i)
		if(count_each_bit[i] * 2 < n)
			best += ((ull)1 << i);
	
	for(i = 0; i < 42; ++i)
		if(((k+1) >> i) & 1){
			x = RIGHT_N_BIT_OFF(k, i+1);
			x |= REMAIN_RIGHT_N_BIT(best, i);
			
			sum = 0;
			for(j = 0; j < 42; ++j){
				if(((x >> j) & 1) == 0)
					sum += (count_each_bit[j] << j);
				else
					sum += ((n - count_each_bit[j]) << j);
			}
			
			if(sum_max < sum)
				sum_max = sum;
		}
	
	printf("%llu", sum_max);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %llu ", &n, &k);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu ", &a);
   ^