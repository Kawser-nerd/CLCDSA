#include <stdio.h>

int count(int n){
	if(n % 2 == 1 && n % 3 != 2)
		return 0;
	if(n % 3 == 2){
		if(n % 2 == 0)
			return 1;
		return 2;
	}
	if(n % 2 == 0){
		if(n % 3 == 0)
			return 3;
	}
	return 1;
}

int main(){
	int sum = 0;
	int n, a;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		sum += count(a);
	}
	printf("%d\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^