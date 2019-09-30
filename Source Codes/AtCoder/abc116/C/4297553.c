#include <stdio.h>

int main(void){
	int n, h[105], log = 0, count = 0, t;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", h + i);
	for(int i = 1; i <= 100; i++){
		t = 0;
		for(int j = 0; j < n; j++){
			if(h[j] >= i && t == 0){
				t = 1;
				count++;
			}else if(h[j] < i && t == 1)t = 0;
		}
	}
	printf("%d\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", h + i);
   ^