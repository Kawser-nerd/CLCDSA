#include<stdio.h>
#include<string.h>

void change(char s[],int len){
	int i,p;
	p=s[0];
	for(i=0;i<len;i++){
		s[i]=s[i+1];
	}
	s[len-1]=p;
}

int main(){
	char s[100],t[100];
	scanf("%s",s);
	scanf("%s",t);

	int i,len=strlen(s);

	for(i=0;i<len;i++){
		change(s,len);
		if(strcmp(s,t)==0){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",t);
  ^