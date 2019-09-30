#include <stdio.h>

int main(void){
	int n, m;
	int x, y, in;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	for(int i = 0; i < n; i++){
		scanf("%d", &in);
		if(x < in)x = in;
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &in);
		if(in < y)y = in;
	}
	if(x < y)printf("No ");
	printf("War\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &n, &m, &x, &y);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &in);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &in);
   ^