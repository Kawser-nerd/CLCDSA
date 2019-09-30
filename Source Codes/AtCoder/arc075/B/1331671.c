#include <stdio.h>
#include <stdlib.h>

#define lli long long int

typedef enum{
	false,
	true
}Boolean;

Boolean canBreak(lli N, lli A, lli B, lli *h, lli k){
	lli i, dec = k * B, rem = 0;
	for(i = 0; i < N; i++){
		if(h[i] > dec){
			rem += 1 + (h[i] - dec - 1) / (A - B);
		}
	}
	if(rem <= k){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	lli N, A, B, i, j, k;
	scanf("%lld%lld%lld", &N, &A, &B);
	lli *h = (lli *)malloc(sizeof(lli) * N);
	lli hmax = 0;
	for(i = 0; i < N; i++){
		scanf("%lld", &h[i]);
		if(h[i] > hmax){
			hmax = h[i];
		}
	}
	//printf("test: hmax = %lld\n", hmax);
	for(j = 1; j <= hmax; j *= 2){}
	//printf("test: j = %lld\n", j);
	for(k = 0; j > 0; ){
		j /= 2;
		//printf("test: k = %lld\n", k);
		if(canBreak(N, A, B, h, k) == true){
			//printf("true\n");
			k -= j;
		}
		else{
			//printf("false\n");
			k += j;
		}
	}
	if(canBreak(N, A, B, h, k) == true){
		printf("%lld\n", k);
	}
	else{
		printf("%lld\n", k + 1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &N, &A, &B);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &h[i]);
   ^