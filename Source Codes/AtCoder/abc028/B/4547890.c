#include <stdio.h>
#include <string.h>
int main(void){
	char s[101];
	int i,a=0,b=0,c=0,d=0,e=0,f=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(s[i]=='A') a++;
		if(s[i]=='B') b++;
		if(s[i]=='C') c++;
		if(s[i]=='D') d++;
		if(s[i]=='E') e++;
		if(s[i]=='F') f++;
	}
	printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^