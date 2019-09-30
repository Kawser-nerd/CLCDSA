#include <stdio.h>

int main(void){
	char b[2];
	scanf("%s",&b);
	if(b[0]=='A'){
		printf("T");
	}
	if(b[0]=='T'){
		printf("A");
	}
	if(b[0]=='C'){
		printf("G");
	}
	if(b[0]=='G'){
		printf("C");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[2]’ [-Wformat=]
  scanf("%s",&b);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&b);
  ^