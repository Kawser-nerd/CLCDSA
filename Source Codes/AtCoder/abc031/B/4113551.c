#include <stdio.h>

int main(void){
	int L, H, n, in;
	scanf("%d %d", &L, &H);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &in);
		if(in < L)
			printf("%d\n", L - in);
		else if(in <= H)
			printf("0\n");
		else
			printf("-1\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &L, &H);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &in);
   ^