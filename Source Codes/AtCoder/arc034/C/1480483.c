#include <stdio.h>
#include <stdlib.h>

#define int long long
#define p (int)(1e9 + 7)

signed main(){
	int A, B, C, i, j, k, e, is_prime = 0, ans = 1;
	scanf("%lld%lld", &A, &B);
	C = A - B;
	int *s = (int *)malloc(sizeof(int) * C);
	for(i = 0; i < C; i++, A--){
		s[i] = A;
	}
	for(k = 2; is_prime == 0; k++){
		is_prime = 1;
		e = 1;
		for(i = 0; i < C; i++){
			while(s[i] % k == 0){
				s[i] /= k;
				e++;
			}
			if(k * k <= s[i]){
				is_prime = 0;
			}
		}
		ans = (ans * e) % p;
	}
	for(i = 0; i < C; i++){
		if(s[i] != 1){
			e = 2;
			for(j = i + 1; j < C; j++){
				if(s[i] == s[j]){
					s[j] = 1;
					e++;
				}
			}
			s[i] = 1;
			ans = (ans * e) % p;
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &A, &B);
  ^