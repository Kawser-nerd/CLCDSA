#include<stdio.h>


int main()
{
	long n,k,x,y,z,m;
	long i, j;
	scanf("%ld %ld", &n,&k);
	for (i = 0; i < n; i++) {
		if (i == 0) {
			scanf("%ld", &y);
			m = y;
			continue;
		}
		scanf("%ld",&x);
		if (x>m) {
			m = x;
		}
		if (x < y) {
			z = y;
			y = x;
			x = z;
		}
		while (x%y != 0) {
			z = y;
			y = x%y;
			x = z;
		}
	}
	if (k%y == 0&&k<=m) {
		printf("POSSIBLE");
		}else{
		printf("IMPOSSIBLE");
	}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld", &n,&k);
  ^
./Main.c:11:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%ld", &y);
    ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&x);
   ^