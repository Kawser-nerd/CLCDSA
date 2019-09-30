#include <stdio.h>

int main(void){
	int n, x = 0, max = 0;
	char c;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++){
		scanf("%c", &c);
		if(c == 'I')x++;
		else x--;
		if(x > max)max = x;
	}
	printf("%d\n", max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n", &n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c", &c);
   ^