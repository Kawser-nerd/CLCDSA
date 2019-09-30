#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e15)

int H, W, T;

int min(int a, int b){
	return a <= b ? a : b;
}

int v_num(int x, int y){
	return x * W + y;
}

signed main(){
	int i, j, k, HW, Xs, Ys, Xg, Yg;
	scanf("%lld%lld%lld", &H, &W, &T);
	HW = H * W;
	char **S = (char **)malloc(sizeof(char *) * H);
	for(i = 0; i < H; i++){
		S[i] = (char *)malloc(sizeof(char) * (W + 1));
		scanf("%s", S[i]);
		for(j = 0; j < W; j++){
			if(S[i][j] == 'S'){
				Xs = i;
				Ys = j;
			}
			if(S[i][j] == 'G'){
				Xg = i;
				Yg = j;
			}
		}
	}
	int **E = (int **)malloc(sizeof(int *) * HW);
	for(i = 0; i < HW; i++){
		E[i] = (int *)malloc(sizeof(int) * HW);
	}
	int l = 0, h, r = inf, cost;
	while(r - l > 1){
		h = (l + r) / 2;
		for(i = 0; i < HW; i++){
			for(j = 0; j < HW; j++){
				E[i][j] = inf;
			}
		}
		for(i = 0; i < H; i++){
			for(j = 0; j < W; j++){
				if(S[i][j] == '#'){
					cost = h;
				}
				else{
					cost = 1;
				}
				if(i > 0){
					E[v_num(i - 1, j)][v_num(i, j)] = cost;
				}
				if(i < H - 1){
					E[v_num(i + 1, j)][v_num(i, j)] = cost;
				}
				if(j > 0){
					E[v_num(i, j - 1)][v_num(i, j)] = cost;
				}
				if(j < W - 1){
					E[v_num(i, j + 1)][v_num(i, j)] = cost;
				}
			}
		}
		for(k = 0; k < HW; k++){
			for(i = 0; i < HW; i++){
				for(j = 0; j < HW; j++){
					E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
				}
			}
		}
		if(E[v_num(Xs, Ys)][v_num(Xg, Yg)] <= T){
			l = h;
		}
		else{
			r = h;
		}
	}
	printf("%lld\n", l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &H, &W, &T);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S[i]);
   ^