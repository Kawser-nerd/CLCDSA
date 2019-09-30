#include <stdio.h>

int main(){
	unsigned long count = 0;
	int n, t, in;
	int tmp;

	scanf("%d %d", &n, &t);
	scanf("%d", &in);
	tmp = in;
	for(int i = 1; i < n; i++){
		scanf("%d", &in);
		if(in <= tmp + t){
			count += in - tmp;
			tmp = in;
		}else{
			count += t;
			tmp = in;
		}
	}
	count += t;
	printf("%ld\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &t);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &in);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &in);
   ^