#include<stdio.h>
int main(){
	int s,temp;
	while(scanf("%c",&s)){
		if(s==' '){
			scanf("%c",&temp);
			break;
		}
	}
	printf("A");
	printf("%c",temp);
		printf("C");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:14: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
  while(scanf("%c",&s)){
              ^
./Main.c:6:10: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
    scanf("%c",&temp);
          ^
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c",&temp);
    ^