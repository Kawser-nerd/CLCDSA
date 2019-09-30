#include<stdio.h>
int main(){
	int i,j=0;
	char s[100010];
	scanf("%s",s);
	for(i=0;s[i];i++){
		if(j==0&&(s[i]=='I'||s[i]=='i'))j++;
		if(j==1&&(s[i]=='C'||s[i]=='c'))j++;
		if(j==2&&(s[i]=='T'||s[i]=='t'))j++;
	}
	printf("%s\n",j-3?"NO":"YES");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^