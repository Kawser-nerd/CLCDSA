#include<stdio.h>
main(){
	char s[10];
	int i;
	scanf("%s",&s);
	for(i=0;i<=9;i++){
		if('0'<=s[i] && '9'>=s[i]){
			putchar(s[i]);
		}
	}
	printf("\n");
	return 0;
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
  scanf("%s",&s);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&s);
  ^