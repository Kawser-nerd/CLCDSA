#include <stdio.h>

int main(void){
	char c, in;
	scanf("%c", &c);
	for(int i = 0; i < 3; i++){
		scanf("%c", &in);
		if(c != in){
			printf("DIFFERENT\n");
			return 0;
		}
	}
	printf("SAME\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c", &c);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c", &in);
   ^