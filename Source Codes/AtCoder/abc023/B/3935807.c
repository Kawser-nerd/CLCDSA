#include <stdio.h>

int check(char *str, int i, int n){
	const char *pat = "bca";
	if(str[i] == pat[(3 - (n / 2) % 3 + i) % 3])
		return 0;
	else
		return 1;
}

int main(){
	int n, f = 1;
	char str[105];

	scanf("%d", &n);
	scanf("%s", str);

	if(n % 2 == 0)f = 0;
	for(int i = 0; i < n; i++){
		if(check(str, i, n)){
			f = 0;
			break;
		}
	}
	if(f)
		printf("%d\n", n / 2);
	else
		printf("%d\n", -1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^