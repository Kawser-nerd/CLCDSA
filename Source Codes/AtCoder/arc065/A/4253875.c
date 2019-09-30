#include<stdio.h>
#include<string.h>

int main(){
	char S[100000];
	scanf("%s",S);
	getchar();
	int l=strlen(S);
	l--;
	int i=0;
	for(i=l;i>0;){
		if(i<4){
			break;
		}
		if(S[i]=='r'&&S[i-1]=='e'&&S[i-2]=='s'&&S[i-3]=='a'&&S[i-4]=='r'&&S[i-5]=='e'){
			i-=6;
		}
		else if(S[i]=='r'&&S[i-1]=='e'&&S[i-2]=='m'&&S[i-3]=='a'&&S[i-4]=='e'&&S[i-5]=='r'&&S[i-6]=='d'){
			i-=7;
		}
		else if(S[i]=='e'&&S[i-1]=='s'&&S[i-2]=='a'&&S[i-3]=='r'&&S[i-4]=='e'){
			i-=5;
		}
		else if(S[i]=='m'&&S[i-1]=='a'&&S[i-2]=='e'&&S[i-3]=='r'&&S[i-4]=='d'){
			i-=5;
		}
		else{
			break;
		}
	}
	if(i==-1){
		printf("YES");
	}
	else{
		printf("NO");
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^