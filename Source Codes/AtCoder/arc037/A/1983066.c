#include <stdio.h>

int main(){
	int N, m, i, ans = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &m);
		if(m < 80){
			ans += 80 - m;
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &m);
   ^