#include<stdio.h>
int main(void){
	char S[4];
	int a;
	int p=0;
	for(a=0;a<4;a++){
		scanf("%c",&S[a]);
		if(S[a]=='+'){
			p++;
		}else{
			p--;
		}
	}
	printf("%d",p);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&S[a]);
   ^