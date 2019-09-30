#include<stdio.h>

int main(){

	int i;
	char S[11] = { 0 };

	scanf("%s", &S);

	S[3] = '8';

	printf("%s", S);
	

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[11]’ [-Wformat=]
  scanf("%s", &S);
        ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &S);
  ^