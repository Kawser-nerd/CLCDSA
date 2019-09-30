#include <stdio.h>
#include <stdlib.h>

#define inf (int)(1e9)

int main(){
	int N, i, j, k, ans = -inf, tak, aok, thentak, aokmax;
	scanf("%d", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < N; i++){
		aokmax = -inf;
		for(j = 0; j < i; j++){
			tak = 0;
			aok = 0;
			for(k = j; k <= i; k++){
				if((k - j) % 2 == 0){
					tak += a[k];
				}
				else{
					aok += a[k];
				}
			}
			if(aokmax < aok){
				aokmax = aok;
				thentak = tak;
			}
		}
		for(j = i + 1; j < N; j++){
			tak = 0;
			aok = 0;
			for(k = i; k <= j; k++){
				if((k - i) % 2 == 0){
					tak += a[k];
				}
				else{
					aok += a[k];
				}
			}
			if(aokmax < aok){
				aokmax = aok;
				thentak = tak;
			}
		}
		if(ans < thentak){
			ans = thentak;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^