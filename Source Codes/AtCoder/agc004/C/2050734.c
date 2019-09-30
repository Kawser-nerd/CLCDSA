#include <stdio.h>
#include <stdlib.h>

int main(){
	int H, W, i, j;
	scanf("%d%d", &H, &W);
	char **a = (char **)malloc(sizeof(char *) * H);
	char **R = (char **)malloc(sizeof(char *) * H);
	char **B = (char **)malloc(sizeof(char *) * H);
	for(i = 0; i < H; i++){
		a[i] = (char *)malloc(sizeof(char) * (W + 1));
		R[i] = (char *)malloc(sizeof(char) * (W + 1));
		B[i] = (char *)malloc(sizeof(char) * (W + 1));
		scanf("%s", a[i]);
		for(j = 0; j < W; j++){
			R[i][j] = a[i][j];
			B[i][j] = a[i][j];
			if(i == 0 || (i < H - 1 && j % 2 == 0)){
				R[i][j] = '#';
			}
			else{
				B[i][j] = '#';
			}
		}
		R[i][W] = '\0';
		B[i][W] = '\0';
	}
	for(i = 0; i < H; i++){
		printf("%s\n", R[i]);
	}
	printf("\n");
	for(i = 0; i < H; i++){
		printf("%s\n", B[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", a[i]);
   ^