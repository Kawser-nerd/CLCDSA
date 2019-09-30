#include <stdio.h>

int main(){
	char n[20];
	scanf("%s",&n);
	int len = strlen(n);
	
	int all9 = 1; // all number *expect the first digil*   is 9
	for(char* i = n+1; *i != NULL; i++){
		if( *i != '9' ){
			all9 = 0;
			break;
		}
	}
	
	int ret = 9 * (len - 1);

	n[1] = NULL;
	ret += atoi( n );
	if( ! all9 ) ret -= 1;

	printf("%d\n", ret);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[20]’ [-Wformat=]
  scanf("%s",&n);
        ^
./Main.c:6:12: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  int len = strlen(n);
            ^
./Main.c:6:12: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:6:12: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:9:24: warning: comparison between pointer and integer
  for(char* i = n+1; *i != NULL; i++){
                        ^
./Main.c:18:7: warning: assignment makes integer from pointer without a cast [-Wint-conversion]
  n[1] = NULL;
       ^
./Main.c:19:9: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
  ret += atoi( n );
         ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&n);
  ^