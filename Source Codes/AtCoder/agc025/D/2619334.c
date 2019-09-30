#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, D1, D2, i, j, k, l, f, g;
	scanf("%d%d%d", &N, &D1, &D2);
	for(k = 0; (D1 & 1) == 0; D1 >>= 1, k++){}
	for(l = 0; (D2 & 1) == 0; D2 >>= 1, l++){}
	int num = 0;
	for(i = 0; i < 2 * N; i++){
		for(j = 0; j < 2 * N; j++){
			if(num == N * N){
				return 0;
			}
			if(((((k&1)|(((i>>(k>>1))^(j>>(k>>1)))&1))&(((k^1)&1)|((i>>(k>>1))&1)))|(((l&1)|(((i>>(l>>1))^(j>>(l>>1)))&1))&(((l^1)&1)|((i>>(l>>1))&1))))==0){
				printf("%d %d\n", i, j);
				num++;
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &D1, &D2);
  ^