#include <stdio.h>
#include <stdlib.h>

#define int long long
#define max_size (int)(1e5 + 1)

signed main(){
	int N, a, i, w, s, t, r, u, m;
	scanf("%lld%lld", &N, &a);
	a--;
	char *k = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", k);
	for(m = 0; k[m] != '\0'; m++){}
	int *b = (int *)malloc(sizeof(int) * N);
	int *c = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &b[i]);
		b[i]--;
		c[i] = -1;
	}
	w = a;
	for(t = 0; c[w] == -1; t++, w = b[w]){
		c[w] = t;
	}
	s = c[w];
	r = t - s;

	if(m <= 18){
		for(u = 0, i = 0; i < m; i++){
			u = (10 * u + (int)k[i] - (int)'0');
		}
		if(u < s){
			for(i = 0; i < N; i++){
				if(c[i] == u){
					printf("%lld\n", i + 1);
					return 0;
				}
			}
		}
		else{
			u = (u - s) % r + s;
			for(i = 0; i < N; i++){
				if(c[i] == u){
					printf("%lld\n", i + 1);
					return 0;
				}
			}
		}
	}
	else{
		for(u = 0, i = 0; i < m; i++){
			u = (10 * u + (int)k[i] - (int)'0') % r;
		}
		u = s + (u - s + r * s) % r;
		for(i = 0; i < N; i++){
			if(c[i] == u){
				printf("%lld\n", i + 1);
				return 0;
			}
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &a);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", k);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &b[i]);
   ^