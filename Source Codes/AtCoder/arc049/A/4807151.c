#include<stdio.h>

int main(){
	int a,b,c,d,i;
	char s[105];
	scanf("%s%d%d%d%d",s,&a,&b,&c,&d);
	for(i=0;s[i]!=0;i++){
		if(i==a||i==b||i==c|i==d){
			printf("\"");
		}
		printf("%c",s[i]);
	}
	if(i==d)printf("\"");
	puts("");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%d%d%d%d",s,&a,&b,&c,&d);
  ^