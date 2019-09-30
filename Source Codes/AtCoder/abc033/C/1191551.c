#include<stdio.h>
#include<stdlib.h>

int main(void){
	int l,i,res = 0,f;
	char s[131072];
	scanf("%s",s);
	l = strlen(s);
	f = 0;
	for(i = 0;i < l;i++){
		if(i%2 == 0){if(s[i] == '0'){f++;}}
		else{if(s[i] == '+'){if(f == 0){res++;}f = 0;}}
	}
	if(f == 0){res++;}
	printf("%d\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:6: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  l = strlen(s);
      ^
./Main.c:8:6: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:8:6: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^