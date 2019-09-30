#include<stdio.h>
int main(){
	int i,l;
	char s[10010];
	scanf("%s",s);
	for(l=0;s[l];l++);
	for(i=0;s[i];i++){//printf("%c %c\n",s[i],s[l-1-i]);
		if(s[i]-s[l-i-1]&&s[i]-'*'&&s[l-i-1]-'*')break;
	}
	printf("%s\n",s[i]?"NO":"YES");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^