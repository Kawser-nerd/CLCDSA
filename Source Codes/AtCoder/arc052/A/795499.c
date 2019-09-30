#include <stdio.h>

#define MAXSIZE 20

int main(void){
	char s[MAXSIZE]={},t[MAXSIZE]={};
	int i,num=0,ans;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){
		if('0'<=s[i] && s[i]<='9'){
			t[num]=s[i];
			num++;
		}
	}
	if(t[1]=='\0'){
		ans=t[0]-48;
	}else{
		ans=(t[0]-48)*10+t[1]-48;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^