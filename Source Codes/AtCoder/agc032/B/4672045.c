#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	if(n & 1){
		printf("%d\n", (n - 1) * (n - 1) / 2);
		for(int i = 2; i <= n / 2; ++i){
			for(int j = 1; j < i; ++j){
				printf("%d %d\n", j, i);
				printf("%d %d\n", n - j, i);
				printf("%d %d\n", j, n - i);
				printf("%d %d\n", n - j, n - i);
			}
		}
		for(int i = 1; i < n; ++i) printf("%d %d\n", i, n);
	}else{
		printf("%d\n", n * (n - 2) / 2);
		for(int i = 2; i <= n / 2; ++i){
			for(int j = 1; j < i; ++j){
				printf("%d %d\n", j, i);
				printf("%d %d\n", n - j + 1, i);
				printf("%d %d\n", j, n - i + 1);
				printf("%d %d\n", n - j + 1, n - i + 1);
			}
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^