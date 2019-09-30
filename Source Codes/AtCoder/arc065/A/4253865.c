#include<stdio.h>
#include<string.h>
int main() {
	char s[100000];
	scanf("%s",s);
	int a[100000]= {0},i,j;
	for(i=0; i<strlen(s); i++) {
		if(s[i]=='d'&&s[i+1]=='r'&&s[i+2]=='e'&&s[i+3]=='a'&&s[i+4]=='m') {
			a[i]=1,a[i+1]=1,a[i+2]=1,a[i+3]=1,a[i+4]=1;
		}
		if(s[i]=='d'&&s[i+1]=='r'&&s[i+2]=='e'&&s[i+3]=='a'&&s[i+4]=='m'&&s[i+5]=='e'&&s[i+6]=='r') {
			a[i]=1,a[i+1]=1,a[i+2]=1,a[i+3]=1,a[i+4]=1,a[i+5]=1,a[i+6]=1;
		}
		if(s[i]=='e'&&s[i+1]=='r'&&s[i+2]=='a'&&s[i+3]=='s'&&s[i+4]=='e') {
			a[i]=1,a[i+1]=1,a[i+2]=1,a[i+3]=1,a[i+4]=1;
		}
		if(s[i]=='e'&&s[i+1]=='r'&&s[i+2]=='a'&&s[i+3]=='s'&&s[i+4]=='e'&&s[i+5]=='r') {
			a[i]=1,a[i+1]=1,a[i+2]=1,a[i+3]=1,a[i+4]=1,a[i+5]=1;
		}
	}
	int f=0;
	for(i=0; i<strlen(s); i++) {
		if(a[i]==0) {
			f=1;
			break;
		}
	}
	if(f==1)
		printf("NO");
	else
		printf("YES");
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^