#include<stdio.h>
#include<string.h>

int main(){
	char a,b;
	scanf("%c %c",&a,&b);
	if(a=='D'){
		if(b=='H'){
			printf("D");
		}
		else{
			printf("H");
		}
	}
	if(a=='H'){
		if(b=='D'){
			printf("D");
		}
		else{
			printf("H");
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c",&a,&b);
  ^