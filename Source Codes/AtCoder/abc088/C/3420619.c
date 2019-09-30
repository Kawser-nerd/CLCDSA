#include<stdio.h>
#include<stdlib.h>
#define TABLESIZE 3 //???????????????
#define BUFFSIZE TABLESIZE*(TABLESIZE+2)

int main() {
	//?????tbl????????????
	int i, j;
	int tbl[TABLESIZE][TABLESIZE];
	char buff[BUFFSIZE];

	//???????
	for (i = 0; i < TABLESIZE; i++) {
		fgets(buff, BUFFSIZE, stdin);
		sscanf(buff, "%d %d %d", &tbl[i][0], &tbl[i][1], &tbl[i][2]);
	}

	//??????(a(i)+b(j))-(a(i+1)+b(j))?
	//(a(i)+b(j+1))-(a(i+1)+b(j+1))?????????????????????
	for (i = 0; i < TABLESIZE - 1; i++) {
		for (j = 0; j < TABLESIZE - 1; j++) {
			//?????????????????????
			if (tbl[i][j] - tbl[i + 1][j] != tbl[i][j + 1] - tbl[i + 1][j + 1]) {
				printf("No\n");
				goto EndFanction;
			}
		}
	}
	printf("Yes\n");

EndFanction:
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buff, BUFFSIZE, stdin);
   ^