#include <stdio.h>
#include <stdlib.h>

int H, W, *is_used, *is_chosen;
char **S, **T;

int sym(int j, int k){
	int i;
	for(i = 0; i < H; i++){
		if(T[i][j] != T[H - 1 - i][k]){
			return 0;
		}
	}
	return 1;
}

int solve(int set_num){
	int i, j, k, res;
	if(set_num == H){
/*		printf("\n");
		for(i = 0; i < H; i++){
			printf("%s\n", T[i]);
		}
*/		int alone_num = 0;
		for(j = 0; j < W; j++){
			is_chosen[j] = 0;
		}
		for(j = 0; j < W; j++){
			if(is_chosen[j] == 0){
//				printf("j = %d\n", j);
				for(k = j + 1; k < W; k++){
					if(is_chosen[k] == 0){
						if(sym(j, k) == 1){
							is_chosen[j] = 1;
							is_chosen[k] = 1;
							break;
						}
					}
				}
				if(is_chosen[j] == 0){
					if(sym(j, j) == 0 || alone_num > 0){
						return 0;
					}
					else{
						is_chosen[j] = 1;
						alone_num++;
					}
				}
			}
//			printf("alone_num = %d\n", alone_num);
		}
		return 1;
	}
	else{
		if(set_num == 0 && H % 2 == 1){
			for(i = 0; i < H; i++){
				T[H / 2] = S[i];
				is_used[i] = 1;
				res = solve(set_num + 1);
				is_used[i] = 0;
				if(res == 1){
					return 1;
				}
			}
			return 0;
		}
		for(i = 0; is_used[i] == 1; i++){}
		T[set_num / 2] = S[i];
		is_used[i] = 1;
		for(k = i + 1; k < H; k++){
			if(is_used[k] == 0){
				T[H - 1 - set_num / 2] = S[k];
				is_used[k] = 1;
				res = solve(set_num + 2);
				is_used[k] = 0;
				if(res == 1){
					is_used[i] = 0;
					return 1;
				}
			}
		}
		is_used[i] = 0;
		return 0;
	}
}

int main(){
	int i, j;
	scanf("%d%d", &H, &W);
	S = (char **)malloc(sizeof(char *) * H);
	for(i = 0; i < H; i++){
		S[i] = (char *)malloc(sizeof(char) * (W + 1));
		scanf("%s", S[i]);
	}
	is_used = (int *)malloc(sizeof(int) * H);
	T = (char **)malloc(sizeof(char *) * H);
	for(i = 0; i < H; i++){
		is_used[i] = 0;
	}
	is_chosen = (int *)malloc(sizeof(int) * W);
	if(solve(0) == 1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:89:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:93:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S[i]);
   ^