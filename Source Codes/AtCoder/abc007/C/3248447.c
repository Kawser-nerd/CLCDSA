#include<stdio.h>

int main() {
	int R, C, sy, sx, gy, gx, i, j, k, y[4] = { -1,1,0,0 }, x[4] = { 0,0,-1,1 }, turn = 0;
	scanf("%d %d", &R, &C);
	scanf("%d %d", &sy, &sx);
	scanf("%d %d", &gy, &gx);
	char c_0[50][50];
	int c[50][50], c_check[50][50];

	for (i = 0; i<R; i++) scanf("%s", c_0[i]);

	for (i = 0; i<R; i++) {
		for (j = 0; j<C; j++) {
			if (c_0[i][j] == '.') c[i][j] = 0;  //??0??????
			else c[i][j] = -1;  //????-1
			c_check[i][j] = 0; //??????????
		}
	}
	c[sy - 1][sx - 1] = 1; //?????????

	while(1) {
		turn++; //?????

		for (i = 0; i<R; i++) {
			for (j = 0; j<C; j++) {
				if (c[i][j] == 1) { //?????????????
					for (k = 0; k<4; k++) {
						if (c[i + y[k]][j + x[k]] == 0) c_check[i + y[k]][j + x[k]] = 1; //???????????????????????
					}

				}

			}
		}

		for (i = 0; i<R; i++) {
			for (j = 0; j<C; j++) {
				if (c[i][j] == 1) c[i][j] = -1; //????????
			}
		}

		for (i = 0; i<R; i++) {
			for (j = 0; j<C; j++) {  
				if (c_check[i][j] == 1) c[i][j] = 1, c_check[i][j] = 0; //?????????????????????
			}
		}

		if (c[gy - 1][gx - 1] == 1) { //???????????????
			printf("%d\n", turn);
			return 0;
		}

	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &R, &C);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &sy, &sx);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &gy, &gx);
  ^
./Main.c:11:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i<R; i++) scanf("%s", c_0[i]);
                        ^