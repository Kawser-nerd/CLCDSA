#include <stdio.h>
#include <stdlib.h>

int digit_count(int n){
	int ans;
	for(ans = 0; n != 0; ans++){
		n >>= 1;
	}
	return ans - 1;
}

int element_count(int n){
	n = (0x55555555 & n) + (0x55555555 & (n >> 1));
	n = (0x33333333 & n) + (0x33333333 & (n >> 2));
	n = (0x0f0f0f0f & n) + (0x0f0f0f0f & (n >> 4));
	n = (0x00ff00ff & n) + (0x00ff00ff & (n >> 8));
	n = (0x0000ffff & n) + (0x0000ffff & (n >> 16));
	return n;
}

//????1?0???
int remove_highest_one_bit(int n){
	int i = n;
	i |= (i >> 1);
	i |= (i >> 2);
	i |= (i >> 4);
	i |= (i >> 8);
	i |= (i >> 16);
	return n ^ i ^ (i >> 1);
}

int main(){
	int N, M, x, y, i, j, ans = 0;
	scanf("%d%d", &N, &M);
	int *connection = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		connection[i] = 1 << i;
	}
	for(i = 0; i < M; i++){
		scanf("%d%d", &x, &y);
		connection[x - 1] |= 1 << (y - 1);
		connection[y - 1] |= 1 << (x - 1);
	}
	int powN = 1 << N;
	int *subset = (int *)malloc(sizeof(int) * powN);
	subset[0] = 1;
	for(i = 1; i < powN; i++){
		if(subset[remove_highest_one_bit(i)] == 1 && ((connection[digit_count(i)] & i) == i)){
			subset[i] = 1;
			if(element_count(i) > ans){
				ans = element_count(i);
			}
		}
		else{
			subset[i] = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x, &y);
   ^