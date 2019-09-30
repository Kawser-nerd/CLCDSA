#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
	return *(long*)a > *(long*)b;
}

long gcd(long a, long b){
	if(a % b == 0)return b;
	return gcd(b, a % b);
}

long absl(long in){
	if(in < 0)return -in;
	return in;
}

int main(void){
	long n, x, in, res;
	scanf("%ld %ld", &n, &x);
	for(int i = 0; i < n; i++){
		scanf("%ld", &in);
		if(i == 0)res = absl(in - x);
		res = gcd(res, absl(in - x));
	}
	printf("%d\n", res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
  printf("%d\n", res);
         ^
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld", &n, &x);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &in);
   ^