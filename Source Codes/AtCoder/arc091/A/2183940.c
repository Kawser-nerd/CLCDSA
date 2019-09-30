#include <stdio.h>
#include <stdlib.h>
#define int long long

signed main(){
	int N, M;
	scanf("%lld%lld", &N, &M);
	if(N == 1 && M == 1){
		printf("%lld\n", 1);
	}
	else if(N == 1 && M > 1){
		printf("%lld\n", M - 2);
	}
	else if(N > 1 && M == 1){
		printf("%lld\n", N - 2);
	}
	else{
		printf("%lld\n", (N - 2) * (M - 2));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:10: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘int’ [-Wformat=]
   printf("%lld\n", 1);
          ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^