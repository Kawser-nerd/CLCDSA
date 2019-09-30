#include<stdio.h>

int main(){
	char N[18];
	scanf("%s",N);
	int l,flag=1;
	for(int i=0;N[i]!='\0';i++){
		l++;
		if(l>=2 && N[i]!='9')flag=0;
	}
	if(flag==1)printf("%d\n",(N[0]-'0')+(l-1)*9);
	else printf("%d\n",(N[0]-'0')+(l-1)*9-1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",N);
  ^