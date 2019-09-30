#include <stdio.h>

int main(){
	int k, n, pass[105];
	int in, f = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		pass[i] = 0;
	scanf("%d", &in);
	pass[in - 1] = 1;
	scanf("%d", &in);
	pass[in - 1] = 1;

	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d", &in);
		if(pass[in - 1] == 1)
			f = 0;
		pass[in - 1] = 1;
	}
	if(f)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &in);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &in);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &k);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &in);
   ^