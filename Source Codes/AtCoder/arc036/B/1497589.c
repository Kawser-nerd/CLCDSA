#include <stdio.h>

#define inf (int)(1e9 + 7)

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int N, h, i, inc = 1, oldh, mount = 1, ans = 1;
	scanf("%d", &N);
	scanf("%d", &oldh);
	for(i = 1; i < N; i++){
		scanf("%d", &h);
		if(inc == -1){
			if(h < oldh){
				mount++;
			}
			else{
				ans = max(ans, mount);
				mount = 2;
				inc = 1;
			}
		}
		else{
			if(h < oldh){
				inc = -1;
				mount++;
			}
			else{
				mount++;
			}
		}
		oldh = h;
	}
	ans = max(ans, mount);
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &oldh);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &h);
   ^