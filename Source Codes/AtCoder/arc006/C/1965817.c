#include <stdio.h>
#include <stdlib.h>
#define inf (int)(1e9)

int can_pile_up(int h, int N, int *w, int *place){
	int i, j, maxw_stwi, thenj;
	for(i = 0; i < h; i++){
		place[i] = inf;
	}
	for(i = 0; i < N; i++){
		maxw_stwi = -1;
		for(j = 0; j < h; j++){
			if(place[j] >= w[i] && maxw_stwi < w[i]){
				maxw_stwi = place[j];
				thenj = j;
			}
		}
		if(maxw_stwi == -1){
			return 0;
		}
		else{
			place[thenj] = w[i];
		}
	}
	return 1;
}

int main(){
	int N, i;
	scanf("%d", &N);
	int *w = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &w[i]);
	}
	int l = -1, h, r = N + 1;
	int *place = (int *)malloc(sizeof(int) * N);
	while(r - l > 1){
		h = (l + r) / 2;
		if(can_pile_up(h, N, w, place) == 1){
			r = h;
		}
		else{
			l = h;
		}
	}
	printf("%d\n", r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &w[i]);
   ^