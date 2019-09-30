#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, sum = 0;
	scanf("%d", &n);
	int *num;
	num = malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++){
		scanf("%d", num + i);
		sum += num[i];
	}
	if(sum % n){
		printf("-1\n");
		return 0;
	}
	int mv = 0, count = 0;
	sum /= n;
	for(int i = 0; i < n - 1; i++){
		if(mv = num[i] + mv - sum)count++;
	}
	printf("%d\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", num + i);
   ^