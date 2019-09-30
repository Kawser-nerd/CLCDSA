#include <stdio.h>

int main(){
	char S[4];
	scanf("%s", &S);
	int sum = 0;
	for(int i=0;i<4;i++){
		if(S[i] == '+') sum += 1;
		else sum -= 1;
	}
	printf("%d", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
  scanf("%s", &S);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &S);
  ^