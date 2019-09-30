#include <stdio.h>

int main(){
	int n, x, sum = 0, tmp;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		if((x >> i) & 1)
			sum += tmp;
	}
	printf("%d\n", sum);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &x);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &tmp);
   ^