#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, M, i, ans = 0;
	scanf("%d%d", &N, &M);
	char *name = (char *)malloc(sizeof(char) * (N + 1));
	char *kit = (char *)malloc(sizeof(char) * (M + 1));
	scanf("%s", name);
	scanf("%s", kit);
	int *name_alf = (int *)malloc(sizeof(int) * 26);
	int *kit_alf = (int *)malloc(sizeof(int) * 26);
	for(i = 0; i < 26; i++){
		name_alf[i] = 0;
		kit_alf[i] = 0;
	}
	for(i = 0; i < N; i++){
		name_alf[(int)name[i] - (int)'A']++;
	}
	for(i = 0; i < M; i++){
		kit_alf[(int)kit[i] - (int)'A']++;
	}
	for(i = 0; i < 26; i++){
		if(kit_alf[i] == 0){
			if(name_alf[i] > 0){
				printf("-1\n");
				return 0;
			}
		}
		else{
			ans = max(ans, (name_alf[i] + kit_alf[i] - 1) / kit_alf[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", name);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", kit);
  ^