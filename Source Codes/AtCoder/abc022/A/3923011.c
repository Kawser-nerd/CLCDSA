#include <stdio.h>

int main(){
	int n, w = 0, s, t, in, count = 0;
	scanf("%d %d %d", &n, &s, &t);
	for(int i = 0; i < n; i++){
		scanf("%d", &in);
		w += in;
		if(s <= w && w <= t)count++;
	}
	printf("%d\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &n, &s, &t);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &in);
   ^