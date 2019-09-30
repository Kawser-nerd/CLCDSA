#include<stdio.h>

int a[26];

int main(){
	char S[200001],T[200001];
	scanf("%s%s",S,T);
	
	int c=0;
	int s[200001],t[200001];
	for(int i=0;i<26;i++)a[i]=0;
	for(int i=0;S[i]!='\0';i++){
		if(a[S[i]-'a']==0){
			c++;
			a[S[i]-'a']=c;
		}
		s[i]=a[S[i]-'a'];
	}
	c=0;
	for(int i=0;i<26;i++)a[i]=0;
	for(int i=0;T[i]!='\0';i++){
		if(a[T[i]-'a']==0){
			c++;
			a[T[i]-'a']=c;
		}
		t[i]=a[T[i]-'a'];
	}
	for(int i=0;S[i]!='\0';i++){
		if(s[i]!=t[i]){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",S,T);
  ^