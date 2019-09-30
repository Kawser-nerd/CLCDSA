#include <stdio.h>

int H, W;

void make_image(char S1[102][102], char S2[102][102], char S3[102][102]);
int check(char S1[102][102], int i, int j);
int strc(char S1[102][102], char S2[102][102]);

int main(void)
{
	int i, j;
	char S1[102][102], S2[102][102], S3[102][102];

	scanf("%d%d", &H, &W);
	getchar();	//????????????

	for (i = 0; i <= H + 1; i++){
		for (j = 0; j <= W + 1; j++){
			S1[i][j] = '.';
			S2[i][j] = '.';
			S3[i][j] = '.';
		}
	}

	for (i = 0; i <= H + 1; i++){
		if (i == 0 || i == H + 1){
			for (j = 0; j <= W + 1; j++){
				S1[i][j] = '#';
				S2[i][j] = '#';
				S3[i][j] = '#';
			}
		} else {
			S1[i][0] = '#';
			S1[i][W + 1] = '#';
			S2[i][0] = '#';
			S2[i][W + 1] = '#';
			S3[i][0] = '#';
			S3[i][W + 1] = '#';
		}
	}

	for (i = 1; i <= H; i++){
		for (j = 1; j <= W; j++){
			S1[i][j] = getchar();
		}
		getchar();	//????????????
	}

	make_image(S1, S2, S3);

/*	for (i = 0; i <= H + 1; i++){
		for (j = 0; j <= W + 1; j++){
			printf("%c", S3[i][j]);
		}
		putchar('\n');
	}*/

	if(strc(S1, S3)){
		printf("impossible\n");
	} else {
		printf("possible\n");
		for (i = 1; i <= H; i++){
			for (j = 1; j <= W; j++){
				printf("%c", S2[i][j]);
			}
			putchar('\n');
		}
	}

	return 0;
}

void make_image(char S1[102][102], char S2[102][102], char S3[102][102])
{
	int i, j, k, l;

	for (i = 1; i <= H; i++){
		for (j = 1; j <= W; j++){
			if(!check(S1, i, j)){
				S2[i][j] = '#';
				for(k = i - 1; k <= i + 1; k++){
					for (l = j - 1; l <= j + 1; l++){
						S3[k][l] = '#';
					}
				}
			}	
		}
	}
}

int check(char S1[102][102], int h, int w)
{
	int i, j;

	for (i = h - 1; i <= h + 1; i++){
		for (j = w - 1; j <= w + 1; j++){
			if (S1[i][j] == '.') return 1; 
		}
	}

	return 0;
}

int strc(char S1[102][102], char S3[102][102])
{
	int i, j;

	for (i = 1; i <= H; i++){
		for (j = 1; j <= W; j++){
			if(S1[i][j] != S3[i][j]){
				return 1;
			}	
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^