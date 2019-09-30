#include<stdio.h>
int main() {
	int sec,tako, cus,i;
	int sell[100],wait[100];
	scanf("%d", &sec);
	scanf("%d", &tako);
	for (i = 0; i < tako; i++) {
		scanf("%d", &sell[i]);
	}
	scanf("%d", &cus);
	for (i = 0; i < cus; i++) {
		scanf("%d", &wait[i]);
	}

	if (cus > tako) {
		printf("no\n"); //????????????
		return 0;
	}
	else
	{
		int count = 0;
		for (i = 0; i < cus; i++) {
			while (1) {
				if (wait[i] - sell[count] >= 0 && count < tako) {
					if (wait[i] - sell[count++] <= sec) {
						break;
					}
				}
				else {
					printf("no\n");
					return 0;
				}
			}
		}
		printf("yes\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &sec);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &tako);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &sell[i]);
   ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &cus);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &wait[i]);
   ^