#include <stdio.h>
#include <string.h>
int main(void){
	char s[101];
	char k[101];
	char ans;
	scanf("%s",&s);
	scanf("%s",&k);
	if( strlen(k)>2){
		//k?100?????
		/*s?0??100??????????1????1?????
		1????????????????*/
		for(int i=0;i<100;i++){
			if( s[i] !='1'){
				printf("%c",s[i]);
				return 0;
			}
		}
		printf("1");
		return 0;
	}else{
		//k?100?????
		/*k????????????s????k????????
		???1????1?????1????????????????
		*/
		int x1=0;
		int x2=0;
		if (strlen(k)>1){
			x2 = k[1]-'0';
		}
		x1 = k[0]-'0';
		int x = x2*10 + x1;
		//printf("x = %d\n",x);
		for(int i=0;i<x;i++){
			if( s[i] !='1'){
				printf("%c",s[i]);
				return 0;
			}
		}
		printf("1");
		return 0;
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
  scanf("%s",&s);
        ^
./Main.c:8:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
  scanf("%s",&k);
        ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&s);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&k);
  ^