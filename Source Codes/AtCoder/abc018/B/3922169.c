#include <stdio.h>

int main(){
	char str[105];
	char tmp;
	int n, l, r;
	scanf("%s", str);
	scanf("%d", &n);
	for(int j = 0; j < n; j++){
		scanf("%d %d", &l, &r);
		l--;
		r--;
		for(int i = 0; i <= (r - l) / 2; i++){
			tmp = str[l + i];
			str[l + i] = str[r - i];
			str[r - i] = tmp;
		}
	}
	printf("%s\n", str);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &l, &r);
   ^