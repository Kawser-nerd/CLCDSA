#include<stdio.h>

int Num = 0;

void water(int *height, int l, int r){
	if (l > r) return;
	int i, min = height[l], Imin = l;
	for (i = l+1; i <= r; i++){
		if (min > height[i]){
			min = height[i];
			Imin = i;
		}
	}
	Num += min;
	for (i = l; i <= r; i++)
		height[i] -= min;
	water(height, l, Imin-1);
	water(height, Imin+1, r);
	return;
}

int main(void){
	int i, N;
	scanf("%d", &N);
	int height[N];
	for (i = 0; i < N; i++)
		scanf("%d", &height[i]);
	water(height, 0, N-1);
	printf("%d\n", Num);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &height[i]);
   ^