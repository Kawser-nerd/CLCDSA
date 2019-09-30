#include<stdio.h>
#include<string.h>
int main(){
	char s[1001];
	scanf("%s",s);
	
	int i=0,j=1,l=strlen(s);
	while(i<l){
		if(s[i]==s[j]){
			j++;
		}
		else{
			printf("%c%d",s[i],j-i);
			i=j;
		}
	}
	puts("");
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^