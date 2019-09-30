#include <stdio.h>

int main(){
	int n, a, b, x, p = 0;
	char dir[5];

	scanf("%d %d %d", &n, &a, &b);
	for(int i = 0; i < n; i++){
		scanf("%s", dir);
		scanf("%d", &x);
		if(x < a)x = a;
		if(b < x)x = b;
		if(dir[0] == 'E')
			p += x;
		else if(dir[0] == 'W')
			p -= x;
	}
	if(p < 0)
		printf("West %d\n", -p);
	else if(p > 0)
		printf("East %d\n", p);
	else
		printf("0\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &n, &a, &b);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", dir);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &x);
   ^