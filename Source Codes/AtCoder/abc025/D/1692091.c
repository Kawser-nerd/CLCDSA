#include <stdio.h>
#include <stdlib.h>
#define p (int)(1e9 + 7)

//n?????1??????
int element_count(int n){
	n = (0x55555555 & n) + (0x55555555 & (n >> 1));
	n = (0x33333333 & n) + (0x33333333 & (n >> 2));
	n = (0x0f0f0f0f & n) + (0x0f0f0f0f & (n >> 4));
	n = (0x00ff00ff & n) + (0x00ff00ff & (n >> 8));
	n = (0x0000ffff & n) + (0x0000ffff & (n >> 16));
	return n;
}

int can_put(int i, int j){
	if(j % 5 != 0 && j % 5 != 4){
		if(((i & (1 << (j - 1))) == 0) ^ ((i & (1 << (j + 1))) == 0)){
			return 0;
		}
	}
	if(j / 5 != 0 && j / 5 != 4){
		if(((i & (1 << (j - 5))) == 0) ^ ((i & (1 << (j + 5))) == 0)){
			return 0;
		}
	}
	return 1;
}

int main(){
	int i, j;
	int *x = (int *)malloc(sizeof(int) * 25);
	int *pos = (int *)malloc(sizeof(int) * 25);
	for(i = 0; i < 25; i++){
		scanf("%d", &x[i]);
		x[i]--;
		pos[i] = -1;
	}
	for(i = 0; i < 25; i++){
		if(x[i] >= 0){
			pos[x[i]] = i;
		}
	}
	int zv25 = 1 << 25;
	int *dp = (int *)malloc(sizeof(int) * zv25);
	for(i = 1; i < zv25; i++){
		dp[i] = 0;
	}
	dp[0] = 1;
	for(i = 0; i < zv25; i++){
		if(pos[element_count(i)] >= 0){
			j = pos[element_count(i)];
			if((i & (1 << j)) == 0 && can_put(i, j) == 1){
				dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i]) % p;
			}
		}
		else{
			for(j = 0; j < 25; j++){
				if(x[j] == -1 && (i & (1 << j)) == 0 && can_put(i, j) == 1){
					dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i]) % p;
				}
			}
		}
	}
	printf("%d\n", dp[zv25 - 1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &x[i]);
   ^