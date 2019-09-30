#include <stdio.h>

int main(void) {
	int n, a, i, cnt = 0, ary[100000] = {};	
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d",& a);
		if(ary[a-1] > 0) cnt++;
		ary[a-1]++;
	}
	printf("%d\n", cnt);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",& a);
   ^