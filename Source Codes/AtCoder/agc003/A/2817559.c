#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[1001];
	int i,a[4]={0},ns=0,we=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(s[i]=='N')a[0]++;
		else if(s[i]=='W')a[1]++;
		else if(s[i]=='S')a[2]++;
		else a[3]++;
	}
	for(i=0;i<4;i+=2)if(a[i]>0)ns++;
	for(i=1;i<4;i+=2)if(a[i]>0)we++;
	puts(ns%2||we%2?"No":"Yes");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^