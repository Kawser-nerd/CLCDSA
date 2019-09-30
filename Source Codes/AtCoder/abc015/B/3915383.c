#include <stdio.h>

int main(){
	int sum = 0, in, count = 0, n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &in);
		if(in != 0){
			count++;
			sum += in;
		}
	}
	printf("%d\n", sum / count + (sum % count ? 1 : 0));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &in);
   ^