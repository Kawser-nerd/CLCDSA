#include<stdio.h>
int main() {
	char X[200001];
	int i = 0, c = 0, len, tmp = 0, ans = 0;
	scanf("%s", &X);
	len = strlen(X);
	while (X[i] != 0)
	{
		if (X[i] == 'S')
		{
			c++;
		}
		else if (X[i] = 'T' && c > 0)
		{
			c--;
			tmp++;
		}
		i++;
	}
	ans = len - tmp * 2;
	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[200001]’ [-Wformat=]
  scanf("%s", &X);
        ^
./Main.c:6:8: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  len = strlen(X);
        ^
./Main.c:6:8: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:6:8: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &X);
  ^