#include <stdio.h>
#include <math.h>

long long multiDimBurger(int n, long long x);

int main(){
	int N;
	long long X;
	scanf("%d", &N);
	scanf("%lld", &X);

	long long count = multiDimBurger(N,X);

	printf("%lld", count);

}

long long multiDimBurger(int n, long long x){
    if (n == 0){
        return 1;
    }
    else if (n > 0){
    	long long t = (long long)pow(2, n+1) - 3;
		if (x == 1){
			return 0;
		}else if (1 < x && x <= 1 + t){
			return multiDimBurger(n-1, x-1);
		}else if (x == 2 + t){
			return multiDimBurger(n-1, x-2) + 1;
		}else if (2 + t < x && x <= 2 + 2 * t){
			return multiDimBurger(n-1, x-2) + 1 + multiDimBurger(n-1, x-2-t);
		}else{
			return 2 * multiDimBurger(n-1, x-2) + 1;
		}
    }
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &X);
  ^