#include<stdio.h>

int main(){
	char s[200001],t[200001];
	int change[26]={-1},change2[26],i;
	for(i=0;i<26;i++){
		change[i]=-1;
		change2[i]=-1;
	}
	scanf("%s%s",s,t);
	for(i=0;s[i]!=0;i++){
		if(change[s[i]-'a']==-1||change[s[i]-'a']==t[i]-'a'){
			change[s[i]-'a']=t[i]-'a';
		}else {
			puts("No");
			return 0;
		}
		if(change2[t[i]-'a']==-1||change2[t[i]-'a']==s[i]-'a'){
			change2[t[i]-'a']=s[i]-'a';
		}else {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s,t);
  ^