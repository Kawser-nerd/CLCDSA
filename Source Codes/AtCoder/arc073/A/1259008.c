#include <stdio.h>

int main(void)
{
	int n, t, x = 0, i, a = 0, b = 0;
	
	int botan[200000];
	
	scanf("%d %d", &n, &t);
	scanf("%d", &a);
	for(i = 0; i < n - 1; i++){
		scanf("%d", &b);
		if(b - a <= t){
			x += b - a;
			
		}else{
			x += t;
			
		}
		a = b;
		
		
	}
	x += t;
	printf("%d\n", x);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &t);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &a);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &b);
   ^