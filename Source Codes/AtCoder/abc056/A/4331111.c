#include<stdio.h>
#include<math.h>
#include<string.h> 
int main() {
	char a,b;
	scanf("%c %c",&a,&b);
	if(a==b){
		printf("H");
	}else{
		printf("D");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c",&a,&b);
  ^