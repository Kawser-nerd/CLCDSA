#include<stdio.h>
#define GridSize 3 
int main(void)
{
	//??????
	int c[GridSize][GridSize];
	int flag = 0;
 
	//3×3?????????
	for (int i = 0; i < GridSize; i++) {
		scanf("%d %d %d\n", &c[i][0], &c[i][1], &c[i][2]);
	}
 
	/*???????????????????????????????????
	  ????c[0][0] - c[1][0] ? c[0][1] - c[1][1]???????*/
	for (int j = 0; j < GridSize - 1; j++) {
		for (int k = 0; k < GridSize - 1; k++) {
			if (c[j][k] - c[j + 1][k] != c[j][k + 1] - c[j + 1][k + 1]) {
				printf("No\n");
                return 0;
			}
		}
	}
		printf("Yes\n");
		
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d\n", &c[i][0], &c[i][1], &c[i][2]);
   ^