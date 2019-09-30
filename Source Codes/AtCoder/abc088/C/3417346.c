#include<stdio.h>
int main(void)
{
	//??????
	int c[3][3];
	int flag = 0;
 
	//3×3?????????
	for (int i = 0; i < 3; i++) {
		scanf("%d %d %d\n", &c[i][0], &c[i][1], &c[i][2]);
	}
 
	/*???????????????????????????????????
	  ????c[0][0] - c[1][0] ? c[0][1] - c[1][1]???????*/
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++) {
			if (c[j][k] - c[j + 1][k] != c[j][k + 1] - c[j + 1][k + 1]) {
				printf("No\n");
                return 0;
			}
		}
	}
		printf("Yes\n");
		
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d\n", &c[i][0], &c[i][1], &c[i][2]);
   ^