#include <stdio.h>
#include <stdlib.h>

int covered_count(int x, int y, char **c){
	int i, j, ans = 1;
	c[x][y] = '.';
	for(i = -1; i <= 1; i++){
		for(j = -1; j <= 1; j++){
			if(c[x + i][y + j] == 'o'){
				ans += covered_count(x + i, y + j, c);
			}
		}
	}
	return ans;
}

int factor_num(int N, int p){
	int ans = 0;
	while(N % p == 0){
		N /= p;
		ans++;
	}
	return ans;
}

int main(){
	int H, W, i, j, covered_num, A_num = 0, B_num = 0, C_num = 0;
	scanf("%d%d", &H, &W);
	char **c = (char **)malloc(sizeof(char *) * H);
	for(i = 0; i < H; i++){
		c[i] = (char *)malloc(sizeof(char) * (W + 1));
		scanf("%s", c[i]);
	}
	for(i = 0; i < H; i++){
		for(j = 0; j < W; j++){
			if(c[i][j] == 'o'){
				covered_num = covered_count(i, j, c);
				if(factor_num(covered_num, 11) % 2 == 1){
					C_num++;
				}
				else if(factor_num(covered_num, 3) % 2 == 1){
					A_num++;
				}
				else{
					B_num++;
				}
			}
		}
	}
	printf("%d %d %d\n", A_num, B_num, C_num);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", c[i]);
   ^