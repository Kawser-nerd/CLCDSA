#include <stdio.h>

int calc_sum(n){
	int Sum = 0;
	for(int i = 1;i <= n;i++)
		Sum += i;
	return Sum;
}

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int idx, ans;
	idx = b - a - 1;
	ans = calc_sum(idx) - a;
	
	printf("%d", ans);
	
	return 0;
} ./Main.c: In function ‘calc_sum’:
./Main.c:3:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
 int calc_sum(n){
     ^
./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &a, &b);
  ^