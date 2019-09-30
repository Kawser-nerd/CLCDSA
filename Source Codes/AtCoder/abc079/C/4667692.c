#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	int arr[9][4];
	int nums[5];
	int i, j, k;
	int count = 8;
	int sum;
	char str[10];
	
	scanf("%d", &nums[0]);

	nums[1] = nums[0] / 1000;
	nums[2] = (nums[0] / 100) % 10;
	nums[3] = (nums[0] / 10) % 10;
	nums[4] = nums[0] % 10;

	arr[1][1] = 1;
	arr[1][2] = 1;
	arr[1][3] = 1;

	arr[2][1] = 0;
	arr[2][2] = 1;
	arr[2][3] = 1;

	arr[3][1] = 1;
	arr[3][2] = 0;
	arr[3][3] = 1;

	arr[4][1] = 1;
	arr[4][2] = 1;
	arr[4][3] = 0;

	arr[5][1] = 0;
	arr[5][2] = 1;
	arr[5][3] = 0;

	arr[6][1] = 0;
	arr[6][2] = 0;
	arr[6][3] = 1;

	arr[7][1] = 1;
	arr[7][2] = 0;
	arr[7][3] = 0;

	arr[8][1] = 0;
	arr[8][2] = 0;
	arr[8][3] = 0;
	for(i = 1; i <= 8; i++) {
		sum = nums[1];
		for(j = 1; j <= 3; j++){
			if(arr[i][j] == 1) {
				sum += nums[1 + j];
			} else if(arr[i][j] == 0) {
				sum -= nums[1 + j];
			}
		}
		if(sum == 7) {
			for(k = 1; k <= 3; k++) {
				if(arr[i][k] == 1) {
					str[2 * k] = '+';
				} else {
					str[2 * k] = '-';
				}
			}
			str[1] = nums[1] + 48;
			str[3] = nums[2] + 48;
			str[5] = nums[3] + 48;
			str[7] = nums[4] + 48;
			str[8] = '=';
			str[9] = '7';
			str[10] = '\0';
			printf("%s", str+1);
			return 0;
		}
	}





	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &nums[0]);
  ^